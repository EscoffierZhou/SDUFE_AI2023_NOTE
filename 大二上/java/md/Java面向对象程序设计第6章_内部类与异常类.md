<img src="https://counter.seku.su/cmoe?name=hiiragi_ansuke_learning&theme=r34"/>

# **第6章:内部类与异常类**

## **1.内部类(常见的类嵌套方式)**

**Java支持一个类中声明另一个类,这种类称作内部类,包含内部类的叫做外嵌类**

>   **使用场景:定义一个类内部的类,可以访问外部类的成员(包括私有成员)**
>
>   >   **如果b类在a类嵌套了,虽然b可以随便使用a的方法,但是出来了就不认识b了**
>   >
>   >   **所以b要是想被调用,需要调用A的所有方法(很麻烦)**
>
>   **包括:成员内部类\静态内部类\局部内部类\匿名内部类**

>   **一个类把内部类看作自己的成员**
>
>   **外部类的成员变量在内部类中有效**
>
>   **\*内部类的方法可以调用外部类的方法**

```java
class OuterClass {
    private String outerField = "Outer Class Field";

    // 定义一个成员内部类
    // InnerClass 是 OuterClass 的成员内部类。
    // 它可以访问外部类 OuterClass 的成员 outerField。
    class InnerClass {
        void display() {
            System.out.println("Accessing from InnerClass: " + outerField);
        }
    }

    void createInnerClass() {
        InnerClass inner = new InnerClass();
        inner.display();
    }
}
public class Main {
    public static void main(String[] args) {
        OuterClass outer = new OuterClass();
        outer.createInnerClass();
    }
}

```

## **2.匿名类(常见的类嵌套方式)**

**java可以使用一个类的子类的类体创建一个子类对象**

>   **使用场景:需要一个类的实例,但是不想单独定义一个类的情况下使用**
>
>   **创建子类使用的两种方法:父类的构造方法/类体**

**匿名类的特点:**

>   **1.匿名类可以继承父类的方法,也可以重写父类的方法**
>
>   **2.使用匿名类,必须是某个类直接使用"匿名类"创建对象,匿名类也是内部类**
>
>   **3.匿名类可以使用外部类的成员变量和方法,`类体中不可以声明static的成员变量和方法`**
>
>   **4.匿名类是一个子类但没有类名,匿名类使用的是父类的构造方法**
>
>   **5.匿名类对象的引用可以传递一个匹配的参数,匿名类对象可以作为方法的实参**

**和接口有关的匿名类**

>   **Java允许直接使用接口名字+类体创建一个匿名对象**
>
>   >   **该类体称作实现了`接口的类去掉类后的声明`,称作匿名类**
>
>   **如果某个方法的参数是接口类型,可以使用该接口名和类体组合一个匿名对象传递该方法的参数**
>
>   **`!类体必须要重写接口中的全部方法`**

```java
interface MyInterface {
    void method1();
    void method2();
}
public class Main {
    public static void main(String[] args) {
        // 匿名类实现了MyInterface接口，并重写了所有方法(或者实现了类的方法)
         MyInterface obj = new MyInterface() {
        // @Override用来告诉编译器和其他开发人员，我们正在重写一个方法，而不是定义新的方法。
            @Override
            public void method1() {
                System.out.println("Method 1 implementation");
            }
            @Override
            public void method2() {
                System.out.println("Method 2 implementation");
            }
        };
        obj.method1();  // 输出: Method 1 implementation
        obj.method2();  // 输出: Method 2 implementation
    }
}
```

## **3.异常类**

**异常处理将会改变程序的控制流程,让程序对错误做出处理**

>   **异常对象调用如下方法输出有关异常的信息**
>
>   **`public String getMessage();`**
>
>   **`public String toString();`**
>
>   **``Public void printStackTrace();`**

**1.`try-catch`语句**

>   ```java
>   // 语法格式
>   try {
>   } catch (Exception e) {
>   }
>   ```
>
>   **将可能出现异常的操作放在try部分,将发生异常后的处理放在catch部分**
>
>   ```java
>   public class Example6_4 {
>     public static void main(String args[ ]) {
>        int n=0,m=0,t=6666;
>        try{ 
>            m=Integer.parseInt("8888");
>            n=Integer.parseInt("ab85"); //发生异常,转向catch
>            t=9999;  //t没有机会赋值
>        }
>        catch(NumberFormatException e) {
>              System.out.println("发生异常:"+e.getMessage());
>              n=123;
>        }
>        System.out.println("n="+n+",m="+m+",t="+t);
>      }
>   }
>   ```

**2.自定义异常类**

>   **可以拓展`Exception类`定义自己的异常类,使用`throw`关键字**
>
>   ```java
>   //IntegerException.java
>   public class IntegerException extends Exception{
>    	String message;
>       public IntegerException(int m){
>        	message="年龄"+m+"不合理";
>       }
>       public String toString(){
>           return message;
>       }
>   }
>   //IntegerException.java
>   public class IntegerException extends Exception
>   {
>       String message;
>       public IntegerException(int m){
>        	message="年龄"+m+"不合理";
>       }
>       public String toString(){
>       	return message;
>   	}
>   }
>   
>   //People.java
>   public class People{
>    	private int age=1;
>       public void setAge(int age) throws IntegerException{
>         if(age>=160&&age<=0){
>           throw new IntegerException(age);
>         }else{
>           this.age=age;
>         }
>       }
>       public int getAge(){
>           System.out.println("年龄"+m+"合理");
>           return age;
>       }
>   }
>   ```

## **4.断言**

**断言用于调试代码阶段时使用,发现错误.使用`assert`**

```java
assert booleanExpression;     // 必须是布尔型的表达式
assert booleanExpression:messageException; 
/*
booleanExpression值为false，程序从断言处停止执行，
为true时，程序从断言处继续执行
booleanExpression值为false，程序从断言处停止执行，并输出messageException的值
为true时，程序从断言处继续执行

*/
assert booleanExpression:messageException;  //可以是字符串的表达式

import java.util.Scanner;
public class Example6_6 {
  public static void main (String args[ ]) {
       System.out.println("请输入正数回车确认");
       Scanner scan=new Scanner(System.in);
       double number=scan.nextDouble();
       assert number>0:"负数不能计算平方根";
       System.out.println(number+"的平方根："+Math.sqrt(number));    
   }
}
```

## **Class类**

**1.获取类的有关信息**

>   **Class是一种类,该类的实例用来封装对象运行时的状态**
>
>   **当一个类被加载和创建的时候,该类相关的Class对象就会自动被创建**
>
>   任何对象调用`getClass`方法都可以获取和该对象相关的一个`Class`对象
>
>   ```java
>   String getName() 返回类的名字
>   Constructor[] getDeclaredConstructors()  返回类的全部构造方法。
>   Field[] getDeclaredFields()  返回类的全部成员变量。
>   Method[] getDeclaredMethods()  返回类的全部方法。            
>   ```
>
>   ```java
>   //Rect.java
>    public class Rect {
>      double width,height,area;
>      public double getArea() {
>         area=height*width;
>         return area;
>      }
>   }
>   
>   import java.lang.reflect.*;
>   public class Example6_7 {
>      public static void main(String args[]) {
>         Rect rect=new Rect();
>          
>         Class cs=rect.getClass(); // 获取了Class
>         String className=cs.getName(); // 获取了name
>         Constructor[] con=cs.getDeclaredConstructors(); // 返回类的全部构造方法。
>         Field[] field=cs.getDeclaredFields() ;// 返回类的全部成员变量。
>         Method[] method=cs.getDeclaredMethods();// 返回类的全部方法。 
>          
>      	  System.out.println("类的名字:"+className);
>         System.out.println("类中有如下的成员变量:");
>         for(int i=0;i<field.length;i++) {
>            System.out.println(field[i].toString());
>         }
>         System.out.println("类中有如下的方法:");
>         for(int i=0;i<method.length;i++) {
>            System.out.println(method[i].toString());
>         }
>         System.out.println("类中有如下的构造方法:");
>         for(int i=0;i<con.length;i++) {
>            System.out.println(con[i].toString());
>         }
>      }  
>   }
>   ```

**2.使用Class实例化一个对象**

>   **创建对象的一般方法是利用new运算符和类的构造方法。**
>
>   **但是Java通过使用Class可以得到一个类的实例。** 
>
>   >   **!!为了使用Class得到一个类的实例**
>   >
>   >   **可以先得到一个和该类相关的Class对象**
>   >
>   >   ```java
>   >   public static Class forName(String className) throws ClassNotFoundException
>   >   ```
>   >
>   >   **就可以返回一个和参数className指定的类相关的Class对象。**
>   >
>   >   **再让这个Class对象调用**
>   >
>   >   ```java
>   >   public Object newInstance() throws InstantiationException,IllegalAccessException
>   >   ```
>   >
>   >   **就可以得到一个`className`类的实例**
>   >
>   >   ```java
>   >   //Circle.java
>   >    public class Circle {
>   >      private double radius,area,length;
>   >      public double getArea() {
>   >         area=Math.PI*radius*radius;
>   >         return area;
>   >      }
>   >      public double getLength() {
>   >         length=2*Math.PI*radius;
>   >         return length;
>   >      }
>   >      public void setRadius(double r) {
>   >         radius=r;
>   >      }
>   >   }
>   >   //Example6_8.java
>   >    public class Example6_8 {
>   >      public static void main(String args[]) {
>   >         try{ 
>   >              Class cs=Class.forName("Circle");
>   >              Circle circle=(Circle)cs.newInstance();
>   >              circle.setRadius(100);
>   >              System.out.println("circle的面积"+circle.getArea());
>   >              System.out.println("circle的周长"+circle.getLength());
>   >          }
>   >          catch(Exception e) {
>   >              System.out.println("不能加载Rect类"+e.getMessage());
>   >          } 
>   >      }  
>   >    }
>   >   ```

