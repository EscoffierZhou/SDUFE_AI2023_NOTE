<img src="https://counter.seku.su/cmoe?name=hiiragi_ansuke_learning&theme=r34"/>

# **第9章 常用实用类**

## **1.String类**

**`Java.lang`包中的String类来创建一个字符串变量,!!字符串变量是对象**

>   **1.常量对象:字符串常量是`双引号括起来的字符序列`:"hello"**
>
>   **2.字符串对象:**
>
>   ```java
>   // 1.声明   
>      String s; 
>   // 2.构造方法:
>      String(s)  
>      String(char a[])
>      String(char a[],int startIndex,int count)
>          
>       String s1=“,mmn”;
>   	String s2=new String(“abd”);
>   	char c[]={‘a’,’m’,’h’};
>   	String s3=new String(c);
>   	String s4=new String(c,0,2);
>   ```
>
>   **3.引用字符串常量对象(内容一致导致变量引用的是同一地址)**
>
>   ```java
>   string s1 = "how are you"; 
>   string s2 = "how are you";
>   // s1和s2的引用指向同一个地址
>   ```

**String类常用的方法**

>   **1.`public int length()`:获取一个字符串的长度**
>
>   **2.`public boolean equals(String a)`:比较当前字符串对象的实体和s的实体是否相同**
>
>   **3.`public boolean startsWith(String s)`:判断当前字符串对象的前缀是否是s**
>
>   **4.`public boolean endsWith(String s)`:判断当前字符串对象的后缀是否是s**
>
>   **5.`public boolean regionMatches(int firstStart,String other,int ortherStart,int length)`:从当前字符串中截取一个字串,和other指定的字串进行比较**
>
>   >   **其重载方法：`public boolean regionMatches( boolean b, int firstStart,String other,int ortherStart,int length)` 
>   >   参数b决定是否区分大小写，为true忽略**
>
>   **6.`public int compareTo(String s)`:按字典序与参数s指定的字符串比较大小**
>
>   >   **`public int compareToIgnoreCase(String s)`:用于比较字母顺序，忽略大小写。**
>   >
>   >   ```java
>   >   String str1 = "Hello";
>   >   String str2 = "hello";
>   >   
>   >   int result = str1.compareToIgnoreCase(str2);
>   >   System.out.println(result); // 输出：0（因为字符串相等，忽略大小写
>   >   
>   >   
>   >   // 负数：表示当前字符串（this）在字典顺序中排在参数字符串（other）之前。
>   >   // 零：表示两个字符串相等（字典顺序相同）。
>   >   // 正数：表示当前字符串在字典顺序中排在参数字符串之后。
>   >   ```
>   >
>   >   ```java
>   >   // 冒泡排序
>   >   //SortString.java 起泡排序
>   >    public class SortString {
>   >      public static void sort(String a[]) {
>   >         for(int i=0;i<a.length-1;i++) {
>   >             for(int j=i+1;j<a.length;j++) { 
>   >                 if(a[j].compareTo(a[i])<0) {
>   >                     //compareTo 方法返回一个整数值，用于指示两个字符串的大小关系。
>   >                     String temp=a[i];
>   >                     a[i]=a[j];
>   >                     a[j]=temp;
>   >                 }
>   >             } 
>   >         }
>   >      }
>   >   }

>   >**6.`public boolean contains(String s):`**
>   >**判断当前字符串对象是否含有参数指定的字符串s** 
>   >
>   >
>   >
>   >**7.`public int indexOf (String s):`**
>   >**从当前字符串的头开始检索字符串s，并返回首次出现s的位置,找不到返回-1**
>   >
>   >>   **indexOf(String s,int startpoint),** 
>   >>   **lastIndexOf(String s)** 
>   >
>   >
>   >
>   >**8．`public String substring(int startpoint)`:**
>   >
>   >**获得一个当前字符串的子串**  
>   >
>   >>   **其相关方法：substring(int start ,int end)**
>   >
>   >
>   >
>   >**9．public String trim() :得到一个s去掉前后空格后的字符串对象。**



**字符串与基本数据的相互转化**

>   **1.`string->int`**
>
>   ```java
>   // java.lang中的Integer 调用方法
>   public static int parseInt(String s) throws NumberFormatException
>       
>   int x; 
>   String s = "123456"; 
>   x = Integer.parseInt(s); 
>   
>   ```
>
>   **2.`int->string`**
>
>   ```java
>   // 可以使用String 类的类方法
>   public static String valueOf（int n）
>   
>   // 可以使用Long类中的类方法
>   public static String toBinaryString(long i)
>   
>   ```

**main中的参数**

>    **`public static void main(String[ ] args)`主方法。**
>
>    **其中参数是字符串数组args，这个数组的元素args[0]……args[n]的值都是字符串。**
>
>    **在Java解释器解释用户的字节码文件时，可以包括需要传给main方法的参数。一般形式为：**
>
>    **`java  类文件名  字符串1  字符串2 …… 字符串n`** 
>    **其中，类文件名和各字符串间用空格分隔。**
>
>    ```java
>    public class c7_7{
>       public static void main(String[ ] args){
>        for(int i=0;i<args.length;i++){
>         System.out.println(args[i]);
>       }
>    }
>    // java c7_7 Hello World Let's Java!”
>    // 输出:
>        Hello
>        World
>        Let's 
>        Java!	
>    ```

***

**4.对象的字符串表示**

>   **所有的类默认的父类是`Object`类**
>
>   **可以使用`public String toString()`获得该对象的字符串表示。**
>
>   >   **返回的一般形式:**
>   >
>   >   ```java
>   >   public String toString() {
>   >       return getClass().getName() + "@" + Integer.toHexString(hashCode());
>   >   }
>   >   //如果你没有重写 toString() 方法,会返回哈希值
>   >   ```
>
>   ```java
>   //Student .java
>   public class Student {
>      String name;
>      public Student() {
>      } 
>      public Student(String s) {
>         name=s;
>      }
>      public String toString() {
>         String oldStr=super.toString();   //建议去掉
>         //它会调用父类 Object 的 toString() 方法。
>         return oldStr+"\nI am a student,my name is "+name;
>      }
>   }
>   //Student .java
>   public class Student {
>      String name;
>      public Student() {
>      } 
>      public Student(String s) {
>         name=s;
>      }
>      public String toString() {
>         String oldStr=super.toString();   //建议去掉
>         return oldStr+"\nI am a student,my name is "+name;
>      }
>   }
>   
>   //Student .java
>   public class Student {
>      String name;
>      public Student() {
>      } 
>      public Student(String s) {
>         name=s;
>      }
>      public String toString() {
>         String oldStr=super.toString();   //建议去掉
>         return oldStr+"\nI am a student,my name is "+name;
>      }
>   }
>   
>   import java.util.Date; 
>   public class Example9_6 {
>      public static void main(String args[]) {
>          Date date=new Date();
>          System.out.println( date.toString());
>          Student zhang=new Student("Zhang San");
>          System.out.println( zhang.toString());  
>          System.out.println(new Student("Li Xiao").toString());  
>      }
>   }
>            
>   
>   ```

**5.字符串与字符\字节数组**

>   **1.字符串与字符数组:**
>
>   >   **构造方法:`String(char[])`和 `String(char[]，int offset，int length)`**
>   >
>   >   **字符串到数组的方法:**
>   >
>   >   >   **(部分)`public void getChars(int start,int end,char c[],int offset ) `**
>   >   >
>   >   >   **(全体)`public char[] toCharArray()`**
>   >
>   >   ```java
>   >   public class Example9_7 {
>   >      public static void main(String args[]) {
>   >         char [] a,b,c; 
>   >         String s="巴西足球队击败德国足球队";
>   >         a=new char[2];
>   >         // 注意getChar方法从start开始,但是不包含end!!
>   >         s.getChars(5,7,a,0);
>   >         System.out.println(a);
>   >         // 从字符串 s 中的索引 5 到 7 的字符提取到字符数组 a 中 
>   >         
>   >         b=new char[s.length()];
>   >         s.getChars(7,12,b,0); // 德国足球队
>   >         s.getChars(5,7,b,5);  // 击败
>   >         s.getChars(0,5,b,7);  // 巴西足球队
>   >         System.out.println(b);
>   >         // 从 s 字符串中提取从索引 7 到 12 的字符，并存入 b 数组的起始位置 0。
>   >          
>   >         c="大家好，很高兴认识大家".toCharArray();
>   >         for(char ch:c) // for-each循环逐个打印c数组的字符
>   >           System.out.print(ch);
>   >      }
>   >   }                 
>   >   ```
>
>   **2.字符串与字节数组**
>
>   >1.**`String(byte[])`用指定的字节数组构造一个字符串对象。**
>   >
>   >2.**`String(byte[]，int offset，int length)`**
>   >
>   >>   **用指定的字节数组一部分，从数组起始位置offset开始取length个构造字符串对象。**
>   >
>   >3.**`public byte[] getBytes()`** 
>   >
>   >4.**`public byte[] getBytes(String charsetName)`** 
>   >
>   >>   **使用参数指定字符编码，将当前字符串转化为一个字节数组。**  

**6.正则表达式与字符串的替换与分解**

>   **1.正则表达式:一些具有特殊意义字符的字符串,由元字符构成**
>
>   >   **比如，“\\dhello”中的\\d就是有特殊意义的元字符，代表0到9中的任何一个。**
>   >
>   >   **可用方法`public boolean matches(String regex)`**
>   >
>   >   >   **判断当前字符串对象和regex的正则表达式是否匹配**
>   >   >
>   >   >   ```java
>   >   >   S=“[159]ABC”，则“1ABC”,  ”5ABC”,  “9ABC”都与s匹配
>   >   >   s=“@\\w{4}”,  则“@abcd”  “@girl”  “@moon”等都与s 匹配
>   >   >   // \\w 表示任意字符
>   >   >   ```
>
>   **2.字符串的替换**
>
>   **`public String replaceAll(String regex,String replacement)`**
>
>   >   **返回一个字符串，该字符串是当前字符串中"所有和参数regex指定的正则表达式匹配的"子字符串被参数replacement指定的字符串替换后的字符串。不影响原字符串**
>
>   ```java
>   String result="12hello567".replaceAll("\\d+","你好");
>   // 那么result就是："你好hello你好" 
>   // "\\d+ " 表示任意一个数字出现一次或 多次
>   ```
>
>   >   ****

## **homework**

```java
public class ExampleStr{
String str = new String("good");
char[]ch = {'a','b','c'};
    publib static void main(String args[]){
        ExampleStr ex = new ExampleStr();
        ex.change(ex.str,ex.ch);
        System.out.print(ex.str+"and");
        System.out.print(ex.ch);
    }
    public void change(String str,char ch[]){
        str = "test ok";
        ch[0]='g';
    }
}
// good and gbc
```

## **后面不讲不考**

****

## **2.StringBuffer类**



## **3.StingTokenizer类**





## **4.Date类**





## **5.Clendar类**





## **6.Math类和BigInteger类**





## **7.DecimalFormat 类**







## **8.\*Pattern与match类**