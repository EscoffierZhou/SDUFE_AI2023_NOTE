<img src="https://counter.seku.su/cmoe?name=hiiragi_ansuke_learning&theme=r34"/>

# **第4章:类与对象**

## **1.类**

#### **1.定义**

**类是组成Java程序的基本要素,它封装了一类对象的状态和方法**

#### **2.类的实现**

**包括两部分:类的声明和类体**

>   **类声明:类的名称**
>
>   **类体:变量声明 + 方法定义**
>
>   ```java
>   class  dog  // class指出这是一个类，dog是类标识
>   {
>      String  name;
>      int  AverageWeight;   //类的属性(静态特征)
>      int  AverageHeight;
>      public void move( )
>        {  ……  }           //类的方法(动态特征)
>      public void ShowDog( )
>        {  ……  }
>   } 
>   ```

#### **3.成员变量和局部变量**

###### **1.变量的类型**

```txt
整型\浮点型\字符型\引用类型:数组对象和接口
```

###### **2.变量的作用范围**

```java
成员变量:作用于"整个类"
局部变量:只在"声明它的方法内"有效
方法参数:在整个方法内"声明之后的位置"有效
```

```java
class A {
   int m = 10, sum = 0;  // 正确初始化成员变量

   void f() {
       int z = 10;  // 将 z 声明在方法内部，确保其作用域有效
       if (m > 9) {
           z = 2 * m + z; 
       }
       for (int i = 0; i < m; i++) {
           sum = sum + i;  // 计算 sum
       }
       m = sum;  // 将 sum 的结果赋值给 m
       // z = i + sum;  // 如果需要，可以将 i 和 sum 的和存储到 z 中
   }
}
```

###### **3.实例变量与类变量static**

>   **在声明变量时,用关键字`static`修饰的称为`类变量`,否则为`实例变量`**
>
>   ```java
>   class dog{float x;static in y;}
>   ```

###### **4.成员变量的隐藏**

>   **如果`局部变量的名字`和`成员变量的名字`相同,则成员变量被隐藏,在这个方法内暂时失效**
>
>   ```java
>   class Tom{
>   int x=98,y;
>   void f(){
>       int x=3;
>    y=x;   // 3有效,98无效
>      }
>   }
>   ```

***

#### **4.方法**

###### **1.方法的定义**

>   **包括两部分:方法声明和方法体**
>
>   ```java
>   int add(int a,int b){
>   	return a+b;
>}
>   void pp(){
>System.out.println("wwwwwwwwww");
>   }
>   
>   ```

###### **2.方法重载**

>   **一个类中可以有多个相同名字的方法,但是参数的个数和类型可能不同**
>
>   ```java
>   class Area{ // 4个getArea方法
>      float getArea(float r){
>        return 3.14f*r*r;
>      }
>   double getArea(float x,int y){
>          return x*y;
>      }
>      float getArea(int x,float y){
>          return x*y;
>      }
>   double getArea(float x,float y,float z){
>          retutn x*x+y*y+z*z;
>      }
>    }
>   ```

###### **3.构造方法(类中的方法)**

(目的:在创建类的时候,可以直接被调用,初始化或者检查初始值是否合法)

**主要用于对象的初始化。** 

当使用`new`关键字创建对象时，会自动调用相应的构造方法来初始化对象的属性。

>   <font color=red>构造方法没有返回类型!!!</font>

```java
class Car {
    String model;
    int year;

    // 构造方法
    Car(String model, int year) {
        this.model = model;  // 用传入的参数初始化字段
        this.year = year;
    }
}
// 类构造以后,调用类会直接调用构造方法
```

###### **4.静态方法**

(不加static的是实例方法,加了static是静态方法)

```java
class A{
int a;
    float max(float x,float y){
        ....
    }
    static float jerry(){
    ..
    }
    static void speak(){
        ....
    }
}
```

###### **5.值得注意的地方**

**1.对类成员变量的修改**

**<font color=red>对类成员变量的操作只能放在方法中</font>,声明变量可以直接赋值**

>   ```java
>// 正确：
>   class A{
>       int a=12;
>       float b=12.34f;
>}
>   
>错误： 
>   class A{
>        int a;
>        float b;
>        a=12;
>        b=12.34f;
>}
>   
>   // 正确： 
>    class A{
>        int a;
>        float b;
>        void f(){ 
>            int x;
>            x=90;
>            a=12;
>            b=12.34f;
>        }
>    }
>    ```

**2.不同方法能操作的类成员**

**实例方法:对类变量(static)/实例变量都可以操作**

**类方法:只能对类变量(static)进行操作**

>   **人话:static的类只能访问static的变量**
>
>   ```java
>   class MyClass {
>       static int classVar = 10;  // 类变量
>       int instanceVar = 20;      // 实例变量
>   
>    // 实例方法
>       void instanceMethod() {
>           // 可以访问类变量
>           System.out.println("Class variable: " + classVar);
>   
>           // 可以访问实例变量
>        System.out.println("Instance variable: " + instanceVar);
>       }
>       // 类方法
>        static void classMethod() {
>           // 可以访问类变量
>            System.out.println("Class variable: " + classVar);
>            // 无法访问实例变量
>            // System.out.println(instanceVar); // 无法访问实例变量
>        }
>    }
>    
>    public class Test {
>        public static void main(String[] args) {
>            MyClass obj = new MyClass();
>            obj.instanceMethod(); // 调用实例方法
>        }
>   }
>   
>```

**3.类和方法的调用**

**一个类的方法可以相互调用(类方法<->OK)**

**实例方法可以调用该类的其它方法(实例->同类Oth OK)**

**类方法不能调用实例方法(static-> 实例方法 NO)**

>   ```java
>class MyClass {
>       int x = 10;
>   
>       // 实例方法
>    void instanceMethod() {
>           System.out.println("Inside instanceMethod, x = " + x);
>    }
>       // 实例方法调用实例方法
>       void method1() {
>           System.out.println("Inside method1");
>           // 调用同类的其他实例方法
>           instanceMethod();
>    }
>   
>       // 类方法
>        static void classMethod() {
>           System.out.println("Inside classMethod");
>            // 编译错误：无法从静态方法调用实例方法
>            // instanceMethod();  // 错误，类方法不能直接调用实例方法
>    
>            // 正确的做法是通过对象调用实例方法
>            MyClass obj = new MyClass();
>            obj.instanceMethod();  // 通过对象调用实例方法
>        }
>    }
>    
>    public class Test {
>        public static void main(String[] args) {
>           MyClass.classMethod();  // 调用类方法
>       }
>}
>   ```

## **2.对象**

#### **1.类与对象的关系**

>   **<font color=red>类:同一类的对象的模板</font>**
>
>   **<font color=red>对象:在主方法中声明的实在的个体</font>**
>
>   **一个类可以按照类的属性产生多个对象**
>
>   ```java
>   class XiyoujiRenwu {  
>      float height,weight;
>      String head, ear,hand,foot, mouth;
>      void speak(String s) {
>         System.out.println(s);
>      }
>   }
>   public class Main {
>       public static void main(String[] args) {
>           // 创建一个 XiyoujiRenwu 类型的对象
>           XiyoujiRenwu person = new XiyoujiRenwu();
>           
>           // 给属性赋值
>           person.height = 170;
>           person.weight = 60;
>           person.head = "头部特征";
>           person.ear = "耳朵特征";
>           
>           // 调用方法
>           person.speak("Hello, Xiyouji!");
>       }
>   }
>   
>   ```

#### **2.创建对象**

>   **1.声明对象:确定`对象的名称`并指明`对象所属的类`**
>
>   **2.初始化\分配存储空间**
>
>   **3.使用或者创建多个其余对象**

#### **3.对象的引用和实体**

>   **用类创建一个对象时,类中的成员变量在分配存储空间,这些内存空间称作对象的实体**
>
>   **如果创建的两个对象有相同的引用,那么就具有完全的实体**
>
>   ```java
>   class Person {
>       String name;
>       int age;
>       // 构造方法
>       Person(String name, int age) {
>           this.name = name;
>           this.age = age;
>       }
>       // 显示对象的内容
>       void display() {
>           System.out.println("Name: " + name + ", Age: " + age);
>       }
>   }
>   
>   public class Test {
>       public static void main(String[] args) {
>           // 创建一个 Person 对象 p1
>           Person p1 = new Person("Alice", 25);
>           // 创建一个引用 p2 指向 p1
>           Person p2 = p1;
>           // 修改 p1 对象的属性
>           p1.name = "Bob";
>           p1.age = 30;
>           // 打印两个对象的内容
>           System.out.println("p1: ");
>           p1.display();  // 输出：Name: Bob, Age: 30
>           System.out.println("p2: ");
>           p2.display();  // 输出：Name: Bob, Age: 30
>           //即使没有修改p2,但是p2也随着p1修改了
>       }
>   }
>   ```

## **3.参数传值**

#### **1.基本数据类型参数的传递**

>   **基本数据类型的参数,向该`参数传递的值的级别`,不可以高于`该参数的级别`**
>
>   **<font color=red>(关注精度)</font>**

```java
public class Test {
    // 方法接受 int 类型参数
    public static void printInt(int num) {
        System.out.println("Received int: " + num);
    }
    public static void main(String[] args) {
        long myLong = 100L;
        // 错误：不能将 long 类型的值传递给 int 类型的参数
        printInt(myLong);  // 编译错误
        printInt((int) myLong);  // 正确
    }
}
```

#### **2.引用类型参数的传递(双向地址传递)**

>   **当参数是引用类型时,传递的是变量中存放的引用,而不是实体(传递"指针",而不是实体)**
>
>   **<font color=red>(关注最终传入的参数名)</font>**
>
>   ```java
>   class Person {
>      String name;
>      // 构造方法
>      Person(String name) {
>          this.name = name;
>      }
>   }
>   // Person.name 
>   public class Test {
>      // 修改对象的属性
>      public static void modifyPerson(Person p) {
>          p.name = "Modified Name";  // 修改形参 p 的 name 属性
>      }
>      public static void main(String[] args) {
>          Person person1 = new Person("Original Name");
>          // 输出：Original Name
>          System.out.println("Before modification: " + person1.name);  
>          // 传递对象引用给方法
>          modifyPerson(person1);//从Personp变成person1
>          // 方法修改了对象的属性，实参也发生了变化
>          // 输出：Modified Name
>          System.out.println("After modification: " + person1.name);  
>      }
>   }
>   // Before modification: Original Name
>   // After modification: Modified Name
>   ```

#### **3.可变参数(输入个数的可变)**

>   **可变参数指在`声明方法时`不给出参数列表中`从某项到最后一项参数的名字和个数`**
>
>   **但这些参数的类型必须相同**
>
>   可变参数使用"..."表示若干个参数,这些参数的类型必须相同,最后一个必须对应
>
>   **<font color=red>(关注输入的类型和最后一个元素)</font>**
>
>   ```java
>   public class Computer {
>     public double getResult(double a, int ... x) {
>        double result=0;
>        int sum=0;
>        // 遍历可变参数 x(可能时数组)，并求和
>        for(int i=0;i<x.length;i++) {
>           sum=sum+x[i]; 
>        }
>        result=a*sum;
>        return result; 
>     }
>   }
>   public class Test {
>      public static void main(String[] args) {
>          Computer computer = new Computer();
>          // 调用 getResult，传递一个 double 和多个 int 参数
>          double result = computer.getResult(5.0, 1, 2, 3, 4);
>          System.out.println("Result: " + result); // 输出：Result: 50.0
>      }
>   }
>   ```

## **4.对象组合**

#### **类中对象的组合**

>   **一个类可以把`对象`作为`自己的成员变量`**
>
>   **<font color=red>(也就是说,对象不仅仅能在Main中实例化,也可以在类中实例化)</font>**
>
>   **如果用这样的类创建对象,那么该对象中就会有其它对象(该对象由几个对象组合而成)**
>
>   ```java
>   /*
>   Geometry 类通过包含 Rectangle 和 Circle 对象作为成员变量，实现了对象的组合，
>   使得 Geometry 类的实例可以同时拥有一个矩形和一个圆形对象。
>   */
>   public class Circle {
>      double x, y, radius;
>   
>      // 设置和获取 x, y 和 radius 的方法
>      public void setX(double a) { x = a; }
>      public double getX() { return x; }
>      public void setY(double b) { y = b; }
>      public double getY() { return y; }
>      public void setRadius(double r) { if (r > 0) radius = r; }
>      public double getRadius() { return radius; }
>   }
>   
>   public class Rectangle {
>      double x, y, width, height;
>   
>      // 设置和获取 x, y, width 和 height 的方法
>      public void setX(double a) { x = a; }
>      public double getX() { return x; }
>      public void setY(double b) { y = b; }
>      public double getY() { return y; }
>      public void setWidth(double w) { if (w > 0) this.width = w; }
>      public double getWidth() { return width; }
>      public void setHeight(double h) { if (h > 0) this.height = h; }
>      public double getHeight() { return height; }
>   }
>   
>   public class Geometry {
>      Rectangle rect;
>      Circle circle;
>      // 构造函数接受一个 Rectangle 和一个 Circle 对象
>      Geometry(Rectangle rect, Circle circle) {
>          this.rect = rect;
>          this.circle = circle;
>      }
>      // 设置 circle 的位置
>      public void setCirclePosition(double x, double y) {
>          circle.setX(x);
>          circle.setY(y);
>      }
>      // 设置 circle 的半径
>      public void setCircleRadius(double radius) {
>          circle.setRadius(radius);
>      }
>      // 设置 rectangle 的位置
>      public void setRectanglePosition(double x, double y) {
>          rect.setX(x);
>          rect.setY(y);
>      }
>   }
>   
>   public class Main {
>      public static void main(String[] args) {
>          // 创建 Rectangle 和 Circle 对象
>          Rectangle rect = new Rectangle();
>          rect.setX(10);
>          rect.setY(20);
>          rect.setWidth(30);
>          rect.setHeight(40);
>   
>          Circle circle = new Circle();
>          circle.setX(50);
>          circle.setY(60);
>          circle.setRadius(15);
>   
>          // 创建 Geometry 对象，将 Rectangle 和 Circle 传递给它
>          Geometry geometry = new Geometry(rect, circle);
>   
>          // 设置 circle 和 rectangle 的位置
>          geometry.setCirclePosition(100, 200);
>          geometry.setRectanglePosition(200, 300);
>   
>          // 打印输出查看结果
>          System.out.println("Circle position: (" + circle.getX() + ", " + circle.getY() + ")");
>          System.out.println("Rectangle position: (" + rect.getX() + ", " + rect.getY() + ")");
>      }
>   }
>   
>   // Circle position: (100.0, 200.0)
>   // Rectangle position: (200.0, 300.0)
>   ```



## **5.static关键字**

(最大的区别在多个对象可以占用一个空间)

#### **1.实例变量和类变量的区别**

```java
变量:
用 static 修饰的变量:"类变量"
不用 static 修饰的变量:"实例变量"
方法:
用 static 修饰的方法:"类方法"
不用 static 修饰的方法:"实例方法"
```

>   **如果类中有`类变量`,那么所有对象的`类变量`都分配给相同的一处内存**
>
>   >   **改变其中一个对象的这个类变量,会影响其它对象的这个类变量**

**<font color=red>在方法中调用该类的变量存在区别!!</font>**

>   **方法中调用该类的`实例变量`:方法/this关键字 进行赋值修改**
>
>   **方法中调用类的`类变量`:通过类名进行调用赋值`A.b=200;`**

#### **2.使用static的意义**

**创建多个对象时,对象会共享相同的类,而不是每个对象都单独分配空间**

>   ```java
>   class Person {
>       // 实例变量，不使用 static
>       String name;
>       int age;
>       public Person(String name, int age) {
>           this.name = name;
>           this.age = age;
>       }
>       public void displayInfo() {
>           System.out.println("Name: " + name + ", Age: " + age);
>       }
>   }
>   class Person {
>       // 静态变量，所有对象共享
>       static int population = 0;
>       String name;
>       int age;
>       public Person(String name, int age) {
>           this.name = name;
>           this.age = age;
>           population++;  // 每创建一个对象，人口数增加
>       }
>       public void displayInfo() {
>           System.out.println("Name: " + name + ", Age: " + age);
>       }
>   }
>   // 调用方式相同,只是从计算机的角度,内存的分配是不一样的
>   public class Test {
>       public static void main(String[] args) {
>           Person person1 = new Person("Alice", 30);
>           Person person2 = new Person("Bob", 25);
>   
>           person1.displayInfo(); // 输出：Name: Alice, Age: 30
>           person2.displayInfo(); // 输出：Name: Bob, Age: 25
>       }
>   }
>   
>   ```

#### **3.static数据成员的特点**

>   **1.它被保存在类的内存区的公共存储单元,而不是单独的空间**
>
>   **2.可以通过`类名+点操作符`进行访问,不需要建立对象**
>
>   **3.static类数据成员任属于类的作用域**

#### **4.实例方法和类方法的区别**

>   **当用`类`创建对象后,类中的`实例方式`才分配入口地址,从而进一步访问`类创建的对象`(调用的时候,每个对象分配入口)**
>
>   **对于类中的类方法,在该类被加载到内存时,就分配了相应的入口地址**

## **6.this 关键字**

#### **1.this能出现的位置**

**可以出现在`实例方法`和`构造方法`中,但不能出现在`类方法中(static)`**

#### **2.this的目的**

**1.在类的方法中调用this,<font color=red>可以反过来调用类的实例变量进行修改赋值</font>**

**2.由于调用的是该类的实例方法,所以即使方法中有重名的,也会访问类的**

#### **3.在实例方法中使用this**

>   **实例方法中`实例成员变量`:`this.成员变量`**
>
>   **实例方法中`static成员`:`类名.成员变量`**
>
>   **当成员变量和局部变量的名字相同,`成员变量前的this`不可省略**
>
>   ```java
>   /*
>   在你提供的例子中，A.x = 100 是不可以的，
>   因为 x 是实例变量（非静态变量），它是属于类的实例（对象）的，而不是类本身。
>   A.x 这样的写法只能用于访问类的静态变量，而不能用于实例变量。
>   */
>   class A {
>       int x; // 实例变量!!
>       static int y; // 静态变量
>   
>       void f() {
>           int x = 90; // 局部变量
>           int y = 89; // 局部变量
>   
>           this.x = 100; // 通过 this 指定当前对象的实例变量 x
>           /*
>               或者(但是这里要求用this)
>               A obj = new A(); // 创建对象
>               obj.x = 100;      // 通过对象访问实例变量
>           */
>           A.y = 200; // 通过类名 A 访问静态变量 y
>   
>           System.out.println(x + "  " + this.x); // 输出：90 100
>           System.out.println(y + "  " + A.y); // 输出：89 200
>       }
>   }
>   ```

###### **同名构造方法的this调用**

>   **<font color=red>在同名的构造方法中调用this,直接对类的变量进行修改</font>**

>   ```java
>   // 注意:this的继承必须在构造方法的第一句
>   class stu {
>       private String name;
>       private int age;
>       private char sex;
>       // 默认构造方法
>       stu() {  
>       }
>       // 构造方法：传递 name
>       stu(String name) {
>           this(); // 调用默认构造方法
>           this.name = name;  // 设置name
>       }
>       // 构造方法：传递 name 和 age
>       stu(String name, int age) {
>           this(name); // 调用stu(String name)构造方法
>           this.age = age; // 设置age
>       }
>       // 构造方法：传递 name, age 和 sex
>       stu(String name, int age, char sex) {
>           this(name, age); // 调用stu(String name, int age)构造方法
>           this.sex = sex; // 设置sex
>       }
>   }
>   public class consthis {
>       public static void main(String args[]) {
>           stu s1 = new stu();                // 调用默认构造方法
>           stu s2 = new stu("aaaa");          // 调用stu(String name)构造方法
>           stu s3 = new stu("bbb", 18);       // 调用stu(String name, int age)构造方法
>           stu s4 = new stu("cccc", 20, 'F'); // 调用stu(String name, int age, char sex)构造方法
>       }
>   }
>   
>   ```
>
>   

## **7.包**

#### **定义**

**包是Java中有效管理类的一个机制**

#### **包名的目的**

**`有效区分名字相同的类`**

>   `com.example.User` 和 `com.test.User` 就是两个不同的类,不会冲突。

```java
package name;//格式
/*
不分主类or类的package区别,只要文件路径对的即可
*/

// 有package    
// src/com/example/MyClass.java
package com.example;
public class MyClass {
    public static void main(String[] args) {
        System.out.println("Hello from MyClass");
    }
}
// 编译时使用 javac：javac src/com/example/MyClass.java。
// 运行时，确保 src 文件夹作为类路径：java -cp src com.example.MyClass



// 无package
// src/MyClass.java
public class MyClass {
    public static void main(String[] args) {
        System.out.println("Hello from MyClass");
    }
}
// 编译时使用 javac：javac src/MyClass.java。
// 运行时，直接执行：java MyClass，因为它在默认包中。


```

## **8.import 语句**

**`一个类`可能需要调用`另一个类声明的对象`作为自己的`局部变量`**

#### **目的**

**调用另一个类的对象**

#### **1.直接调用`类库中的类`**

```java
import java.util.Date;
public class Example4_12 {
    public static void main(String args[]) {
       Date date=new Date();
       System.out.println("本地机器的时间:"); 
       System.out.println(date);   
    }
}
```

#### **2.调用自定义包中的类**

```java
package tom.jiafei;
public class Triangle {  
    double sideA,sideB,sideC;
    boolean isTriange;
    public Triangle(double a,double b,double c) { 
       sideA=a;
       sideB=b;
       sideC=c;
       if(a+b>c&&a+c>b&&c+b>a) {
          isTriange=true;
       }    
       else {
          isTriange=false;
       }
    }
```

#### **3.使用无包名的类(同目录)**

>   **将这个`无包名的类`的字节码和`当前类`保存在同一目录下**

#### **4.注意点**

>   **(不同包)如果无包名和有包名的类名相同,不能省略包名**
>
>   **(相同包)如果引入相同包的不同类,不能省略包名**

#### **5.访问权限**

>   **`private\protected\public`**
>
>   **其中`private`表示私有变量和私有方法,使用范围在本类的内部,不能跨类**
>
>   **其中`public`修饰的成员变量和方法,称为共有变量和共有方法**

#### **6.友好变量和友好方法(同包)**

**同包中的不同类和不同方法**

>   **加了public可以随便调用,没有加只能放在同一包中作为`友好类`**

#### **7.可访问的权限**

```txt
安全类型      private  default  protected  public
同一类          yes        yes       yes       yes
同一包的类         -         yes       yes       yes
不同包的子类       -          -        yes       yes
不同包的非子类     -          -         -        yes

!!注意:不能用protected和private修饰类,只能用于修饰方法
```

#### **8.基本类型的类包装**

>   ```java
>   数据类型:"byte、int、short、long、float、double、char、boolean"
>       
>   对应的类:"Byte、Integer、Short、Long、Float、Double、Character、Boolean"
>   
>   目的:
>   // 1.可以直接通过调用类的方法,快速完成某些操作
>   // 2.使用集合：Java 的集合框架（ArrayList、HashMap）只能存对象类型不能存基本数据类型
>   // 3.使用泛型：Java 泛型只能使用对象类型
>   // 4.方法支持：很多 API 或库方法需要对象作为参数，而不是基本数据类型。
>   char ch = 'a';
>   char upper = Character.toUpperCase(ch);  // 转换为大写 'A'
>   char lower = Character.toLowerCase(ch);  // 转换为小写 'a'
>   
>   int x = Integer.parseInt("123"); // 将字符串 "123" 转换为 int 类型
>   ```

#### **9.自动装箱和拆箱（Autoboxing and Unboxing）**

>   ```java
>   Integer x = 5; // 自动装箱，将 int 5 转换为 Integer 对象
>   // 或者可以Integer(int num)进行封装
>   int y = x;  // 自动拆箱，从 Integer 对象转换为 int
>   
>   // 注意过程
>   Integer m=x+y;  
>   //1.Integer m=new 开了一个箱
>   //2.Integer(x.intValue()+y.intValue()); 先拆箱再装箱
>   
>   ```

## **9.反编译器和文档生成器**

#### **1.java反编译**

>   **JDK提供的反编译器`javap.exe`将字节码反编译成源码**

#### **2.javadoc制作文档**

>   **JDK提供的编辑器`javadoc.exe`将源文件做成html格式文档**

#### **3.jar文件**

>   **JDK提供的`jar.exe`将类的字节码文件压缩成jar,然后可以直接用该jar的类创建对象**

## **10.总结**

1.类是组成Java源文件的基本元素,一个源文件是有若干个类组成的。

2．类体可以有两种重要的成员：成员变量和方法。

3．成员变量分为实例变量和类变量。

  类变量被该类的所有对象共享；

  不同对象的实例变量互不相同。

4.除构造方法外,其它方法分为实例方法和类方法。

  类方法不仅可以由该类的对象调用,也可以用类名调用；

   而实例方法必须由对象来调用。