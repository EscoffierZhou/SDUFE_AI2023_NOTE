<img src="https://counter.seku.su/cmoe?name=hiiragi_ansuke_learning&theme=r34"/>

# **第一章 Java语言概述**

****

**目录:**

```txt
1.Java 的诞生
2.Java 的特点(重点)
3.JDK
4.一个简单的Java程序
5.联合编译
6.注释
7.编程风格
```

***

## **1. Java的诞生**

Java是**1995年6月由Sun公司**发明的革命性编程语言。     

Java可以**在计算机的操作系统之上再提供一个Java运行环境**，

>   该运行环境由Java虚拟机、类库以及一些核心文件组成，因此可以**处处可用**

## **2. Java的特点**

**1.简单** 

**2.面向对象**

**3.平台无关**

**4.多线程**

**5.安全** 

**6.动态**  

## **3.JDK**

**Java的三个版本**

```txt
（1）Java SE（曾称为J2SE）称为Java标准版或Java 标准平台。  
（2）Java EE（曾称为J2EE）称为Java企业版或Java企业平台。
（3）Java ME（曾称为J2ME）称为Java微型版或Java小型平台。 
都包括了相应的Java虚拟机:
->虚拟机负责将字节码文件加载到内存，然后采用解释方式来执行字节码文件.
->根据相应平台的机器指令翻译一句执行一句。 
```

## **4.Java程序的开发步骤**

>   **1.编写源文件**:编写.java文件
>
>   **2.编译Java源程序**:使用Java编译器(javac.exe)
>
>   **3.运行Java程序**:使用Java编译器(java.exe)

## **5.一个简单的Java程序**&联合编译

```java
public class Hello {
         public static void main (String args[]) {
              System.out.println("这是一个简单的Java应用程序");
              Student stu=new Student();
              stu.speak("We are students");  
        }
  }
 class Student {
       public void speak(String s) {
            System.out.println(s);
       }
 }
// 1. 命名为Hello.java 保存至C:\chapter1 。
// 2．编译Java源程序。 C:\chapter1\>javac  Hello.java 
// 3. 运行Java程序。  C:\chapter1\>java  Hello
.java (源代码) --> javac (编译器) --> .class (字节码) --> ClassLoader (类加载器) --> JVM (Java虚拟机) --> 操作系统
```

## **6.注释**

**单行注释://**

**多行注释:/\*\*/**

## **7.编程风格**

 1 、Allmans风格

Allmans风格也称“独行”风格，即左、右大括号各自独占一行。

2 、 Kernighan风格

Kernighan风格也称“行尾”风格，即左大括号在上一行的行尾，而右大括号独占一行 。 

## **Oth**

```java
///源文件的保存:如果源文件有多个类,只能有一个类是public
        //如果有一个类是public,那么源文件的名字必须和类的名字完全相同.java
        //如果没有public类,只要源文件的名字和某个类名字相同.java
            //比如public的类是Main,那么该文件名应该是Main.java
        ///(1.编译)保存格式ANSI(GBK编码)或者UTF-8
            //使用ANSI在终端打开:java Hello.java
            //使用UTF-8在终端打开:encoding utf-8 Hello.java(必须显式encoding)
            //应用程序的主类:Java程序必须含有一个: // public static void Main(String args[])
        ///(2解释)在主类所在目录,并且运行主类 //java Main (这里Main是程序的主类)
```

