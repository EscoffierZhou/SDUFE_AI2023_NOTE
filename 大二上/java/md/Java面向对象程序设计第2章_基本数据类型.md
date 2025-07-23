<img src="https://counter.seku.su/cmoe?name=hiiragi_ansuke_learning&theme=r34"/>

# **第2章:基本数据类型**

**目录:**

```txt
1. 标识符和关键字
2. 基本数据类型
3. 从命令行输入、输出数据
4. 数组*
5. 枚举类型
```

## **1 标识符和关键字**

**1.标识符**

>   **用来标识类名/变量名/方法名/类型名/数组名/文件名**
>
>   **规定:**
>
>   >   1.   标识符由字母、下划线、美元符号$和数字组成，长度不受限制。          
>   >
>   >   2.   标识符的第一个字符`不能是数字字符`,只能是字母/下划线/美元符号$。🥹         
>   >
>   >   3.   标识符不能是关键字(关键字的大写没问题):
>   >
>   >   `(例如:boolean、byte、short、int、float、double、char、if、else)`
>   >
>   >   4.   标识符不能是true、false和null
>   >
>   >   5.   标识符区分字母的大小写(和Python不一样)
>
>   `比如class(关键字)123variable(数字开头)都是不合法的`

**2.关键字**

```txt
abstract	cast	default	  		final	  	goto*		int
operator	rest	synchronized	try			boolean
catch		do		finally			if			interface
outer		return	this			var			break
char		double	float			implements	long
package		short	throw			void		...
```



## **2.基本数据类型**

>   8种基本数据类型习惯上可分为以下四大类型：    
>
>   逻辑类型：boolean(true,false)    
>
>   整数类型：byte、short、int、long    
>
>   ```java
>   byte 内存分配给1个字节，占8位(数字大小为 -2^7 ~ 2^7-1)
>       
>   short 内存分配给2个字节，占16位
>       
>   int 内存分配给4个字节,占32位.有四种表示方法:十进制/八进制/十六进制/二进制
>   
>   long 内存分配给8个字节，占64位.有四种表示方法:十进制/八进制/十六进制/二进制,可以之前声明Long,也可以之后加上L
>   ```
>
>   字符类型：char
>
>   ```java
>   char 内存分配给2个字节，占16位
>   转义字符常量:\n(换行), \b(退格),\t(水平制表),\‘(单引号),\“(双引号),\\(反斜线)
>   ```
>
>   浮点类型：float、double
>
>   ```java
>   float 内存分配给4个字节，占32位,保留8位有效数字(!!!后面必须要有后缀f或F否则会丢失精度😊)
>   //比如float x =12.4;(错误) 可以是float x = 12.4F; 或者是 float x = (float)12.4;
>       
>   double 内存分配给8个字节，占64位,保留16位有效数字，实际精度取决于具体数值。(不加f就是double了)
>   ```

>   精度转换:
>
>   **按精度从“低”到“高”排列：byte  short  char  int  long  float  double**    
>
>   **低到高自动,高到低手动:**      
>
>   >   格式:byte b = (byte)128 #显式转换后的类型



## **3.从命令行输入、输出数据**

#### 1.**命令行输入**

>   通过创建Scanner类创建一个对象输入(必会)🧐：

>   ```java
>   Scanner reader = new Scanner(System.in)
>   ```
>
>   **方法执行时都会堵塞，程序等待用户在命令行输入数据回车确认。**
>
>   `nextBoolean()、 nextByte()、 nextShort()、 nextInt()
>   nextLong()、nextFloat()、nextDouble()`
>
>   **主要用法是先创建reader再赋值的时候使用**
>
>   ```java 
>   Scanner reader = new Scanner(System.in)
>   double x = reader.nextDouble();
>   ```

#### 2.**命令行输输出**

>   **<font color=red>(注意`import java.util.Scanner;`)</font>**
>
>   2.1 通过`System.out.print`
>
>   **主要方式：`System.out.printLn`和`System.out.print`(区别是有无line转行)**
>
>   ```java
>   System.out.println("Hello"+"World");
>   ```
>
>   2.2 通过`System.out.printf`
>
>   **类似C语言的输出方式**
>
>   >   ```txt
>   >   %d：输出int类型数据值          
>   >   %c：输出char型数据。
>   >   %f：输出浮点型数据，小数部分最多保留6位   
>   >   %s：输出字符串数据。
>   >   %md：输出的int型数据占m列   
>   >   %m.nf：输出的浮点型数据占m列，小数点保留n位。
>   >   ```
>
>   ```java
>   System.out.println(“%d %f”,12,23.78);
>   ```

#### **3.输入输出的程序举例**

```java
import java.util.Scanner;
        public class Example2_3 {
            public static void main (String args[ ]){
                System.out.println("请输入若干个数，每输入一个数回车确认");
                System.out.println("最后输入数字0结束输入操作");
                Scanner reader=new Scanner(System.in);
                double sum=0;
                int m=0;
                double x = reader.nextDouble();
                while(x!=0){
                   m=m+1;
                   sum=sum+x;
                   x=reader.nextDouble();
              }
        System.out.println(m+"个数的和为"+sum);
        System.out.println(m+"个数的平均值"+sum/m);
            }
        }
```

## **4.数组**

#### **1.声明数组:**

>   **元素类型 + 数组名 + [] /元素类型 + [] + 数组名**
>
>   >   一维数组: `float boy[]`;或者 `float[] boy`;
>   >   二维数组: `char cat[][]`;或者`char[][]cat`;
>   >
>   >   **(其中二维数组至少一个[]有数字即可，否则会视为引用)**

#### **2.数组的初始化new：**

>   **数组必须先new初始化才能继续操作，否则没有分配空间**
>
>   >   **1.直接一起声明：`float boy[] = new float[4];`**
>   >
>   >   **2.先声明再初始化：`float boy[];boy[] = new float[4];`**
>   >
>   >   !**注意是否赋初值影响数组的长度`a[i].length`**

#### **3.数组Length的查询：**

>   **对一维数组：`a.length`返回length**
>
>   **对二维数组：**
>
>   >   `a.length`**返回数组的行数**
>   >
>   >   `a[row].length`**返回对应行的列数**
>
>   **对索引进行查询:**
>
>   >   **索引不存在/对应索引元素不存在$\rightarrow$抛出ERROR**
>   >
>   >   `ArrayIndexOutOfBoundsException`

#### **4.数组引用(复制)**

**只有相同维度的数组才能进行赋值,并且不会创建副本,而是两者公用一个引用地址**

>   **同时需要注意的是,初始化完后声明a=b,会把b的映射到a,a的数组会消失**
>
>   (人话:如果a=b,a数组的指针会直接指向b,而a原来的数组被释放)

**如果真的需要复制数组可以使用:**

**1.`arraycopy`**

```java
arraycopy(sourceArray,index1,TransferredArray,index2,length)
```

>   表示将SA的(从index1以后->长为length的部分)转移到TA的(index2开始的数组之后)
>   **需要注意的是SA可以无所谓,但是TA必须先声明才能继续复制**

**2.`copyOf`和`copyOfRange`**

>   **`copyof`将整个数组中元素复制到另一个数组**

```java
public Static double[] copyOf(double[]original,int newLength)
```

>   **`copyOfRange`将数组部分元素复制到另一个数组**
>
>   ```java
>   public static double[] copyOfRange(double[] original,int from,int to) 
>   ```

#### **5.数组的表示格式**

5.1:直接使用`System.out.println(a)`

5.2:转换为string类后输出(能保留[])

>   **`Arrays.toString(a)`注意除了a的部分都是固定格式**

#### **6.排序与二分查找**

>   **1.对数组全部进行升序排列**

```java
public static void sort(double a[])
```

>   **2.对数组部分进行升序排列**

```java
public static void sort(double a[],int start,int end)
```

>   **3.对数组进行二分法查找**

```java
public static int binarySearch(double[] a, double number)
// 查找number是否存在,返回索引或负数
```

```java
import java.util.*; //把工具全导入了
public class Example2_7 {
    public static void main(String args[]) {
      int [] a={12,34,9,23,45,6,45,90,123,19,34};
      Arrays.sort(a);
      System.out.println(Arrays.toString(a));
      int number=45;
      int index=Arrays.binarySearch(a,number);    
      if(index>=0){
         System.out.println(number+"和数组中索引为"+index+"的元素值相同");   
      }
      else{
         System.out.println(number+"不与数组中任何元素值相同"); 
      }
   }
}

```

## 5.**枚举类型**

#### **直接举例**

```java
enum name{
    constant list;
    ...
}
```

**比如**

```java
enum Season {
   春季,夏季,秋季,冬季   
}
public class Example2_8{
   public static void main(String args[]){
        Season x=Season.春季;
        System.out.println(x);
        x=Season.夏季;
        System.out.println(x);
        x=Season.秋季;
        System.out.println(x);
        x=Season.冬季;
        System.out.println(x);
   }
}
```

