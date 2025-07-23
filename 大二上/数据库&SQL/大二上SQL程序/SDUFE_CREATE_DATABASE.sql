USE SDUFE;
GO

-- 创建表
CREATE TABLE dbo.MyTable (
    ID INT PRIMARY KEY,
    Col1 INT,
    Col2 INT,
    Col3 INT,
    Col4 INT,
    Col5 INT,
    Col6 INT,
    Col7 INT
);
GO

-- 插入数据
INSERT INTO dbo.MyTable (ID, Col1, Col2, Col3, Col4, Col5, Col6, Col7) VALUES
(1, 10, 20, 30, 40, 50, 60, 70),
(2, 15, 25, 35, 45, 55, 65, 75),
(3, 20, 30, 40, 50, 60, 70, 80),
(4, 25, 35, 45, 55, 65, 75, 85),
(5, 30, 40, 50, 60, 70, 80, 90),
(6, 35, 45, 55, 65, 75, 85, 95),
(7, 40, 50, 60, 70, 80, 90, 100),
(8, 45, 55, 65, 75, 85, 95, 105);
GO

-- 添加新列
ALTER TABLE dbo.MyTable
ADD [New Column] INT;
GO

-- 更新新列数据
UPDATE dbo.MyTable
SET [New Column] = CASE
    WHEN ID = 1 THEN 3
    WHEN ID = 2 THEN 6
    WHEN ID = 3 THEN 7
    WHEN ID = 4 THEN 8
    WHEN ID = 5 THEN 21123
    WHEN ID = 6 THEN 124
    WHEN ID = 7 THEN 123
    WHEN ID = 8 THEN 567
END;
GO

-- 查询数据(有条件)
SELECT [New Column]
FROM dbo.MyTable
WHERE [New Column] > 20;
Go

-- 查询数据(无条件)
SELECT [New Column]
FROM dbo.MyTable