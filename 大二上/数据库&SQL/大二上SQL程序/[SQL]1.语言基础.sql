USE SDUFE; --在主console控制台中更改上下文
GO
SELECT * FROM SDUFE.dbo.MyTable
WHERE Col1 > 30;
GO
-- 第一章:SQL基础

    --1.了解Transact-SQL编程语言
        --了解:
            --1.Transact-SQL语言是SQL Server在SQL语言的基础上增加了一些语言要素后的扩展语言
            --2.Transact-SQL主要包括管理数据库对象，检索、插入、修改和删除对象数据。
        --架构:
            --Intro:架构是单个用户所拥有的数据库对象的集合，这些对象形成单个命名空间。
            --1.用户架构分离。架构与数据库用户分离对数据库所有者和开发人员而言有许多好处。
                --数据库对象由架构所拥有，而架构由数据库用户或角色所拥有。
                --架构与数据库用户分离对数据库所有者和开发人员而言有许多好处。
            --2.如果系统未定义 DEFAULT_SCHEMA，则数据库用户将把 DBO 作为其默认架构。
        --语言:
            --1.数据定义语言:数据库定义对象使用CREATE/ALTER/DROP等完成
            --2.*数据操纵语言:查/添/改/删 数据库中数据的语句:SELECT/INSERT/UPDATE/DELETE
            --3.数据控制语言:用于设置或者更改数据库用户或角色权限的语句:GRANT/DENY/REVOKE
            --4.控制流语句:BEGIN->END/IF->ELSE/WHILE/BREAK/GOTO/WAITFOR/RETURN
        --语法:
            --简单输出:PRINT(常量|@局部变量|表达式|函数) #每次只能输出一个常量或者一个局部变量或表达式的值
                PRINT 369+2
            --无源查询(无副作用查询):SELECT的无源查询用来查询不在表中的数据,起到数据简单输出的作用
                --SELECT(常量/变量/函数/表达式[AS 别名]/[,..n])
                SELECT 369 AS 'A1',369+2 AS  'A3'
                --先定义后输出(自定义变量)
                DECLARE @A520 INT
                SET @A520=5201314;
                PRINT @A520

    --2.Transact-SQL语法要素
            --1.编码:
                --ASCII码:只能表示256个不同字符
                --Unicode码:拥有65000多个可选的值,不同语言的系统之间不需要任何编码转换
            --2.标识符:用于命名的名称
                --常规标识符:
                    --开头:字母/#/下划线
                    --后续:字母/数字/下划线
                    --要求:不能嵌入空格或特殊字符
                --分隔标识符:不符合常规标识符的标识符必须用方括号表示(注意是标识符不是变量的名字)
            --3.常量:文字值/标量值:表示一个特定数据值的符号,在整个过程常量的值和表现形式保证不变
                --格式取决于表示的值的数据类型
                --1.字符串常量:字符串常量括在单引号内并包含字母数字字符以及特殊字符
                    --Escape:句内引号使用两个单引号进行Escape
                    --[空字符串]的长度为0,[空格字符串]的长度为4
                    --设置unicode:在字符串常量前面添加N前缀(比如:N'China'),每个字符使用2个字节
                --2.二进制常量:二进制常量具有0x并且是十六进制数字字符串.这些常量不使用引号括起
                    --(使用0x前缀进行标记):0xAE,0x69048AEFDD010E
                --3.bit常量:使用数字0或1表示(如果有大于1的,转换为1)
                --4.时期时间常量:datetime常量使用特定的格式并且使用单引号
                    --'September 17,2009';
                    --'9/17/2009';
                    --'20090919';
                    --'15:24:30'
                --5.整型常量:没有用引号括起来/不包含小数点/必须使用数字
                --6.数值型常量:没有用引号括起来/包含小数点/必须使用数字
                --7.浮点型常量:float和real常量一般使用科学计数法表示(101.5E5->101.5*10000)
                --8.货币型常量:使用$、¥、€作为前缀,主要作用是直接筛选出存在前缀的字符
            --4.变量:在程序运行或操作过程中可以改变其值的量(变量名+数据类型+变量值):可参与运算或者作为参数
                --系统提供的全局变量
                    --引用全局变量时,必须以@@开头
                    SELECT GETDATE() AS '当前的日期和时间',
                    @@CONNECTIONS  AS  '试图登录的次数'
                --用户自定义的局部变量
                    --局部变量的声明:被引用时必须先DECLARE然后在前面加上标志@进行使用:DECLEAR{@local_variable data_type}[,..n]表示长度
                        DECLARE @A520 INT--FLOAT/CHAR(N)[固定长度]/VARCHAR[可变长度]/BIT/BINARY
                    --局部变量赋值:未赋值会直接初始化NULL
                        SET @A520=5201314; --SET只能赋单值
                    --局部变量修改:必须使用SELECT/SET命令
                        DECLARE @1 INT,@2 INT --SELECT赋多个值(需要二次声明)
                        SELECT @1 = 10, @2 = 20;
                        SELECT @1,@2;
                        go
            --5.注释:
                    --单行注释:使用--(只有一个是不行的)
                    --多行注释:使用/*...*/
    --3.运算符/函数/表达式
        --1.算术运算符:+-*/%(加减乘除取余)
            --需要注意的是数的表示:同种小数的不同表示会有不同结果
                SELECT 5/2,5.0/2
            --需要注意的是取余操作:如果有负数会取它的绝对值
        --2.比较运算符:除了常规的5个以外还有!=(不等于<>) !<(不小于,>=) !>(不大于,<=)
        --3.逻辑运算符:
            --运算符:
                --AND/OR/NOT/IN(表中和目标有一样的返回TRUE)/BETWEEN/EXISTS
                --ANY(or多元操作)/ALL(AND多元操作)/SOME(多元有TRUE返回TRUE)
            --通配符:
                --%:LIKE'%CPU%'(查找是否包含CPU单词)'%A'(A开头的单词)
                --_:LIKE'_en'(查找以en结尾的所有3个字母的字符串)
                --[]:LIKE'[C-P]ars'(查找C-P开头,ars结尾的单词)
                --[^]:LIKE'de[^I]%'(查找de开始,不以I结尾的单词)
            --注意:对于含有中文的字符串查找,使用Unicode,即N'周兴'
        --4.字符串连接运算符:+
        --5.位运算符:只能用于整数或二进制类型数据
            --&:按位'与'操作      -- 1 & 1 = 1    1 & 0 = 0   0 & 0 = 0
                SELECT 6 & 3 ;  -- 6: 110, 3: 011 -> 110 & 011 = 010 = 2
            --|:按位'或'操作      -- 1 | 1 = 1    1 | 0 = 1   0 | 0 = 0
                SELECT 6 | 3 ;  -- 6: 110, 3: 011 -> 110 | 011 = 111 = 7
            --^:按位'异或'操作    -- 1 ^ 1 = 0    1 ^ 0 = 1   0 ^ 0 = 0
                SELECT 6 ^ 3 ;  -- 6: 110, 3: 011 -> 110 ^ 011 = 101 = 5
            --~:按位'取反'操作    -- 1 变为 0，0 变为 1 (如果取反后是负数就输出负数)
                SELECT ~6;  -- 6: 000000110 -> ~000000110 = 111111001 = -7
        --6.赋值运算符:=
        --7.运算符优先级:
            --  ()
            --  +,-,~  正负,位非
            --  *,/,%  乘除,取模
            --  +,-,+,& 加减,连接,位与
            --  比较运算符
            --  ^,|     位异或,位或
            --  NOT
            --  AND
            --  OTHER(ALL,ANY,BETWEEN,IN,LIKE,OR,SOME)
            --  =   赋值

    --4.Transact-SQL控制流语句(部分:)
        --数学:
            --ABS()/CEILING()/FLOOR()/PI()/POWER(expression,y)/RAND(type)
            --ROUND(expression,length,[0/1]):length对指定位数截断,最后的参数是舍入和截断
            --SQRT()平方根/SQUARE()平方
        --聚合函数:
            --AVG/COUNT/MAX/MIN/SUM
            --STDEV(返回所有值的标准偏差)/VAR(返回所有值的方差)
                --AVG Example
                    DECLARE @finalAvg_1 float
                    SET @finalAvg_1 = (SELECT AVG(col1)FROM MyTable)
                    PRINT '@finalAvg_1='+convert(nvarchar(10),@finalAvg_1) --float类型不能直接输出,需要转换为nvarchar
                    /*vchar和nvarchar都是支持Unicode的,char和nchar适合固定长度*/
                --MAX/MIN Example
                    DECLARE @finalMax float,@finalMin float
                    SET @finalMax = (SELECT MAX(Col1)FROM dbo.MyTable)
                    SET @finalMin = (SELECT MIN(Col1)FROM dbo.MyTable)
                    PRINT
                        '@finalMax_1='+convert(nvarchar(10),@finalMax)
                    PRINT
                        '@finalMin_1='+convert(nvarchar(10),@finalMin)
                --STDEV(返回所有值的标准偏差)/VAR(返回所有值的方差)Example
                    DECLARE @finalStdev float,@finalVar float
                    SET @finalStdev = (SELECT STDEV(Col1)FROM dbo.MyTable)
                    SET @finalVar = (SELECT VAR(Col1)FROM dbo.MyTable)
                    PRINT
                        '@finalStdev_1='+convert(nvarchar(10),@finalStdev)
                    PRINT
                        '@finalVar_1='+convert(nvarchar(10),@finalVar)
        --时间函数:
            --GETDATE():获取当前系统日期和时间,返回日期时间类型(DD MM YY TIME+AM/PM)
            --DATEDIFF(unit,date1,date2):以unit为单位计算date2减去date1的差值,返回整数
            --DAY(date)/MONTH(date)/YEAR(date)
            DECLARE @d datetime ,@daydiff int
            SET @d = getdate()
            SET @daydiff = datediff(DAY,'2025/07/25',@d)
            PRINT N'距离修士考试还有'+ convert(nvarchar(10),@daydiff) + N'天'
        --转换函数:CAST/CONVERT(显式转换/还有SQL server 2022的隐式转换)
            --CAST(expression AS data_type[(length)]) --遵守严格转换机制,适用于对于特定格式的转换
                PRINT N'今天的日期是(CAST)' + CAST(GETDATE() AS VARCHAR(12))
            --CONVERT(data_type[(length)],expression[,style])
                PRINT N'今天的日期是(CONVERT)'+CONVERT(VARCHAR(12),GETDATE(),101)
        --字符串函数:
            --ASCII(character_expression):返回首字符的ASCII代码值
            --CHAR(integer_expression):将int型的ASCII值转化为具体的字符(0-255之间,超出返回NULL)
            --LEN(string_expression):返回字符个数.*不包含尾随空格
                DECLARE @s2 varchar(20),@s3 varchar(20),@s4 varchar(20), @s5 varchar(20)
                SET @s2='ShandongUniversity'   --18
                SET @s3='Shandong University'  --19
                SET @s4='Shandong University ' --19*
                SET @s5=' Shandong University' --20
                SELECT LEN(@s2) as 's2',LEN(@s3) as 's3',LEN(@s4) as 's4',LEN(@s5) as 's5'
            --CHARINDEX(expression1,expression2):返回字串1在字串2的起始位置,否则返回0
                DECLARE  @s varchar(20)
                SET @s='Shandong University'
                Print N'字串的位置在'+convert(nvarchar(10),charindex('Shan',@s))
                Print N'字串的位置在(不存在)'+convert(nvarchar(10),charindex('None',@s))
            --LEFT(expression,integer_expression)返回从左到右expression的integer部分
            --RIGHT(expression,integer_expression)返回从右到左expression的integer部分
                DECLARE  @s varchar(20)
                SET @s='Shandong University'
                PRINT N'LEFT:'+LEFT(@s,8)
                PRINT N'RIGHT'+RIGHT(@s,10)
            --SUBSTRING(expression,start,end)返回子字符串
            --LTRIM(exrpession)删除起始空格
            --RTRIM(expression)删除尾随空格
            --REPLACE(expression1,expression2,expression3):在字符串1中把所有的字符串2用字符串3表示
            --UPPER(expression):全部大写
            --LOWER(expression):全部小写































