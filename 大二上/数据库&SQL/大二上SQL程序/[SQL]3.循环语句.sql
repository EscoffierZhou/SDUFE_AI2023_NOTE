--WHILE语句:
    --主要构成:条件+循环代码块+(结果输出)
    --主要条件:循环初始化+循环头+循环体
        DECLARE @BASE INT = 1, @CNT INT = 0, @SUM INT = 0
        while @CNT < 100
            BEGIN
                SET @SUM = @SUM + @BASE --注意值的迭代需要使用SET
                SET @BASE = @BASE + 1
                SET @CNT = @CNT + 1
            END
        PRINT 'THE ANSWER IS ' + CAST(@SUM AS VARCHAR(10))
    --注意:无论何种类型的循环结构，其共同的特点是必须确保循环体的重复执行能被终止
    --和C语言不一样的是SQL不能出现死循环（即非无限循环，或不能死循环）
        --原因:SQL 是一种声明式语言，它旨在执行查询语句，并返回结果，而不是执行循环语句
        --后果:
            --服务器资源占用：死循环可能会占用服务器的资源，导致其他查询语句无法执行。
            --服务器崩溃：如果死循环导致服务器资源不足，可能会导致服务器崩溃。
            --数据库性能下降：死循环可能会导致数据库性能下降，影响其他查询语句的执行速度。
    --计算1~50之间能被5整除的整数之和。
        --对于缩进很敏感,if最后不需要end
        DECLARE  @sum  int
        DECLARE  @i  int
        SET  @sum = 0
        SET  @i = 1
        WHILE (@i <= 50)
        BEGIN
            IF (@i%5=0)
                BEGIN
                  SET  @sum = @sum + @i
                  PRINT @i
                END
            SET  @i = @i + 1
        END
        PRINT '@sum='+convert(nvarchar(10),@sum)
        --输出图形1:
        DECLARE  @n  int
        SET  @n=1
        WHILE  @n<=6
           BEGIN
             PRINT REPLICATE('@', @n) --按照后件int的数量输出n个前件
             SET  @n=@n+1
           END
        --输出图形2:
        DECLARE  @n  int
        SET  @n=1
        WHILE  @n<=6
           BEGIN
             PRINT REPLICATE(' ',6-@n)+ REPLICATE('#',@n)
             SET  @n=@n+1
           END
        --输出图形3:
        DECLARE @n int, @i int, @j int
        DECLARE @s nvarchar(30)
        SET @n=7
        SET @i=1
        WHILE (@i<=@n)
          BEGIN
            SET @j=1
            SET @s=''
            WHILE (@j<=@i)
              BEGIN
                SET @s=@s+LTRIM(STR(@j))
                SET @j=@j+1
              END
            PRINT @s
            SET @i=@i+1
          END




