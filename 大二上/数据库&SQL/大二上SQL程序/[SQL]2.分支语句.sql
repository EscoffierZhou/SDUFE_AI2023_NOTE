--Transact-SQL控制流语句
    --控制流语句主要用于控制SQL语句/语句块/执行分支循环的语句
    --不使用控制流语句,则SQL按照出现的顺序先后执行
    --1.BEGIN...END语句(主要用途在分支语句控制)
        --!!!否则IF或ELSE条件只能影响一个Transact-SQL语句。
        --语法形式:
        /*
        BEGIN{
            SQL_statement|block
        }
        END
        */
        DECLARE @MyVar float
        SET @MyVar=1.80
        IF  @MyVar>=10.8
          BEGIN
            SET @MyVar = 123.456
            PRINT N'变量@MyVar的值为：'
            PRINT CAST(@MyVar AS varchar(12 ))
          END
        ELSE
          PRINT N'变量@MyVar的值为：' + CAST(@MyVar AS varchar(12 ))
    --2.If相关语句
        --2.1 IF语句（单分支选择结构）
            DECLARE @state  nvarchar(20)
            DECLARE @grade float
            SET @state = N'参加了考试'
            SET @grade=50
            IF @grade >=60
                SET @state=@state+ N'，通过'
            PRINT @state
        --2.2 IF…ELSE语句（双分支选择结构）
            --语法结构:
            /*
            IF  Boolean_expression
                { sql_statement | statement_block }(a1)
            ELSE
                { sql_statement | statement_block }(a2)
            */
            DECLARE @score float, @finalavg float
            SET @score=95.6
            SELECT @finalavg=(SELECT AVG(col1) FROM MyTable)
            IF @score>=@finalavg
                SELECT @score, N'高于期末平均成绩'
            ELSE
                SELECT @score, N'低于期末平均成绩'
        --2.3 嵌套IF…ELSE语句
            DECLARE @score float, @grade char(1)
            SET @score=85
            IF (@score>=90)
                SET @grade='A'
            ELSE IF (@score>=80)
                SET @grade='B'
            ELSE IF (@score>=70)
                SET @grade='C'
            ELSE IF (@score>=60)
                SET @grade='D'
            ELSE
                SET @grade='E'
            PRINT @grade
    --3.CASE语句 --不能在THEN中添加操作,只能输出
        --简单的CASE形式:
          /*
          CASE input_expression
            WHEN expression THEN expression
          ...[n*CASE]
            ELSE result_expression
          EDM
          */
        DECLARE @score float
        SET @score=36.5
        PRINT
        CASE (CAST(@score AS int)/10)
            WHEN 9 THEN 'A'
            WHEN 8 THEN 'B'
            WHEN 7 THEN 'C'
            WHEN 6 THEN 'D'
            ELSE 'E'
        END
        --搜索的CASE语句:
            /*
             CASE
                WHEN Bool_expression THEN expression
                [..n]
             END
             */
        DECLARE @score float
        SET @score=66.5
        PRINT
        CASE
          WHEN @score>=90 THEN 'A'
          WHEN @score>=80 THEN 'B'
          WHEN @score>=70 THEN 'C'
          WHEN @score>=60 THEN 'D'
          ELSE 'E'
        END


























