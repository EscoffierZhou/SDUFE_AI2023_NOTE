--202318140413 周兴

/*
1.输入整数@n.求出1~@n范围内能被3整除,但不能被5整除的所有正整数的和
*/
DECLARE @n INT,@CNT INT,@SUM INT
SET @n = 100 --输入任意值
SET @CNT = 1
SET @SUM = 0
WHILE @CNT <= @n
BEGIN
    IF @CNT % 3 = 0 AND @CNT % 5 != 0
        BEGIN
            SET @SUM = @SUM + @CNT
        END
    SET @CNT = @CNT + 1
END
PRINT N'对于'+convert(nvarchar(10),@n)+N'最后的答案是'+convert(nvarchar(10),@SUM)

--202318140413 周兴
--2.判断给定的整数是否是素数
DECLARE @INPUT INT, @CNT INT
SELECT @INPUT = 47, @CNT = 2
IF @INPUT <= 1
    BEGIN
        PRINT N'输入的数字不是素数'
    END
ELSE
    BEGIN
        WHILE @CNT <= SQRT(@INPUT)
        BEGIN
            IF @INPUT % @CNT = 0
            BEGIN
                PRINT CONVERT(nvarchar(10), @INPUT) + N'不是素数'
                BREAK
            END
            SET @CNT = @CNT + 1
        END
        IF @CNT > SQRT(@INPUT)
        BEGIN
            PRINT CONVERT(nvarchar(10), @INPUT) + N'是素数'
        END
    END

--202318140413 周兴
--问题3:求最大公约数(直接法)
DECLARE @NUM1 INT, @NUM2 INT, @CNT INT, @MAX_GCD INT
SELECT @NUM1 = 12, @NUM2 = 18, @CNT = 1, @MAX_GCD = 0
IF @NUM1 > @NUM2
    BEGIN
        SELECT @CNT = @NUM1
    END
ELSE
    BEGIN
        SELECT @CNT = @NUM2
    END
WHILE @CNT > 0
    BEGIN
        IF @NUM2 % @CNT = 0 AND @NUM1 % @CNT = 0
        BEGIN
            IF @CNT > @MAX_GCD
            BEGIN
                SET @MAX_GCD = @CNT
            END
        END
        SET @CNT = @CNT - 1
    END

PRINT CONVERT(nvarchar(10), @NUM1) + N'和'+CONVERT(nvarchar(10),@NUM2)+N'的最大公约数是'+CONVERT(nvarchar(10), @MAX_GCD)

--202318140413 周兴
--问题3:求最大公约数(辗转相除法)
DECLARE @INIT1 INT,@INIT2 INT,@NUM1 INT, @NUM2 INT, @REM INT
SELECT @INIT1 = 12,@INIT2 =18,@NUM1 = @INIT1, @NUM2 = @INIT2
IF @NUM2>@NUM1 --保证NUM1始终最大
    BEGIN
        DECLARE @TRANS INT
        SET @TRANS = @NUM1
        SET @NUM1 = @NUM2
        SET @NUM2 =@TRANS
    end
SET @REM = @NUM1 % @NUM2
WHILE @REM != 0
    BEGIN
        SET @NUM1 = @NUM2
        SET @NUM2 = @REM
        SET @REM = @NUM1 % @NUM2
    end
PRINT CONVERT(nvarchar(10), @INIT1) + N'和'+CONVERT(nvarchar(10),@INIT2)+N'的最大公约数是'+CONVERT(nvarchar(10), @NUM2)





















