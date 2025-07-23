<img src="https://counter.seku.su/cmoe?name=hiiragi_ansuke_learning&theme=r34"/>

# **第5章:继承与接口**

## **1.子类与父类**

**操作方法**

**先编写一个共有属性的一般类，根据该类继续编写具有特殊属性的新类**

>   **`子类`由继承得到的类  `父类`被继承的类**
>
>   ```java
>   class child extends father{
>      ...
>   }
>   ```

## **2.子类的继承性**

>   **子类继承父类的`成员变量`:**
>
>   >   **作为自己的一个成员变量,可以被子类自己定义的任何实例方法操作**
>
>   **子类继承父类的`方法`:**
>
>   >   **作为子类的一个方法,可以被子类自己定义的任何实例方法操作**

## **3.子类和父类在同包的继承性**

>   **如果子类和父类在一个包中**
>
>   >   **子类自然继承了父类中"不是`private`"的变量,作为自己的`成员变量`**
>   >
>   >   **子类自然继承了父类中"不是`private`"的方法,作为自己的`方法`**
>   >
>   >   **继承的`成员变量`或`方法`的访问权限保持不变**
>
>   ```java
>   // Father.java
>   public class Father { 
>       private int money;
>       int weight;
>       int getWeight() { 
>          return weight ;
>       }
>       protected void setWeight(int w) {
>          weight=w;
>       }    
>   }
>   // Son.java
>   public class Son extends Father { 
>       String hand;
>       public void setHand(String hand) {
>           this.hand=hand;
>       }
>       String getHand() {
>           return hand;
>       } 
>   } 
>   //Grandson.java 
>   public class Grandson extends Son {
>       String foot ;
>       public void setFoot(String foot) {
>          this.foot=foot;
>       }
>       String getFoot() {
>          return foot;
>       } 
>   }
>   //Example5_1.java
>   public class Example5_1 {
>       public static void main(String args[]) {
>           Son son=new Son();
>           Grandson grandson=new Grandson();
>   
>           son.setWeight(62);
>           son.setHand("一双大手"); 
>           grandson.setWeight(29);
>           grandson.setHand("一双小手");
>           grandson.setFoot("一双小脚");
>   
>           System.out.println("儿子的手:"+son.getHand());
>           System.out.println("儿子重量:"+son.getWeight());
>           System.out.println("孙子重量:"+grandson.getWeight()); 
>           System.out.println("孙子的手:"+grandson.getHand()); 
>           System.out.println("孙子的脚:"+grandson.getFoot()); 
>           //子类Son继承了父类Father的weight变量和getWeight()、setWeight()方法
>           //孙子类Grandson继承了Son类的weight变量、getWeight()、setWeight()方法、			hand变量以及setHand()、getHand()方法。
>           //子类和孙子类,都不能继承父类的money类
>       }
>   }
>   ```

## **4.子类和父类不在同一包中的继承性**

>   **子类继承父类的`protected`,`public`的成员变量,作为子类的`成员变量`**
>
>   **用子类创建对象时,不仅子类中声明的成员变量分配了内存,父类的成员变量也分配内存空间**
>
>   >   **父类取一部分分配给`子类对象`的变量**
>
>   ```java
>   public class A {
>        private int x;
>        public void setX(int x) {
>            this.x=x;
>        } 
>        public int getX() {
>            return x;
>        }
>   }
>   public class extends A {
>        double y=12;
>        public void setY(int y){   
>            //this.y=y+x; 非法，子类没有继承x
>        }
>        public double getY() {
>           return y;
>        }
>   }
>   public class Example5_2 {
>     public static void main(String args[]) {
>         B b=new B();
>         b.setX(888);
>         System.out.println("子类对象未继承的x的值是:"+b.getX());
>         b.y=12.678;
>         System.out.println("子类对象的实例变量y的值是:"+b.getY());
>     }  
>   }
>   ```

## **5.成员变量的隐藏和方法重写**

#### **1.成员变量的隐藏**

**对于子类可以从父类继承的成员变量**

只要子类中声明的`成员变量`和父类中声明的`成员变量`相同时

->子类就隐藏了继承的成员变量(要进行进一步操作)

**<font color=red>人话:子类有父类相同成员名,用自己的</font>**

>   ```java
>   class People {
>     public double x;
>     public void setX(double x) {
>        this.x=x;
>     }
>     public double getDoubleX() {
>        return x;
>     }
>   }
>   class Student extends People {
>     int x; //通过定义同名变量x来隐藏父类中的x
>     // 调用子类时,使用的x时子类的x
>     public int getX() {
>        return x;
>     }
>   }
>   ```

#### **2.方法重写**

**子类可以通过重写,隐藏`已继承的实例方法`**

>   **语法规则:**
>
>   **子类中定义的方法,这个方法的`方法类型`和父类的方法类型一致**
>
>   **子类中定义的方法,这个方法的`方法名字` \ `参数个数` \ `参数类型`和父类一致**

**重写的目的:隐藏继承的方法\把父类的状态和行为->自身的状态和行为**

**<font color=red>人话:通过继承方法,可以给出两个模板,主类调用可选</font>**

>   ```java
>   class A {
>       double f(float x,float y) {
>          return x+y;
>       }
>       public int g(int x,int y) {
>          return x+y;
>       }
>   }
>   class B extends A {
>       double f(float x,float y) {
>          return x*y;
>       }  
>   }
>   public class Example5_4 {
>       public static void main(String args[]) {
>         B b=new B();
>         double result=b.f(5,6);     //b调用重写的方法
>         System.out.println("调用重写方法得到的结果:"+result);   
>         int m=b.g(3,5);        //b调用继承的方法
>         System.out.println("调用继承方法得到的结果:"+m);  
>       } 
>   } 
>   ```
>
>   ```java
>   // 覆盖和方法重写的不同点
>   1. 覆盖
>      "同一个类"中定义多个"同名方法"(参数\返回值...不同)
>      "所以覆盖发生在同一个类的内部"
>   2. 重写
>      "方法重写"是子类重写定义父类的一个方法,"必须和父类方法签名完全一致"
>      "所以重写发生在父类和子类"
>      "执行子类时,如果遇到重写,将会执行重写后的方法" 
>       添加 @override 注解明确表明重写了父类
>       ->不加也无法,"加上后帮助编译器确认是否正确重写了父类的方法"
>       class A {
>           public void doSomething() {
>               System.out.println("Doing something in A");
>           }
>   	}
>       class B extends A {
>           @Override
>           public void dosomething() {  // 错误：方法名大小写不匹配
>               System.out.println("Doing something in B");
>           }
>       }
>       /*
>       error: method does not override or implement a method from a supertype
>       public void dosomething() {  // 错误：方法名不匹配
>       */
>   ```
>

#### **3.重写方法的注意事项**

>   **(操作)方法的覆盖\数据成员的隐藏:**
>
>   >   **子类隐藏父类只是不可见,但是父类的成员依然拥有独立的内存空间**
>   >
>   >   **子类方法对父类方法的覆盖:清除父类方法占用的内存,父类方法在子类中不再存在**
>
>   **(重写)子类`重写`定义父类已有的方法,"必须"和父类完全相同**
>
>   **(权限)覆盖方法时,不能使用比父类被覆盖方法更严格的访问权限**
>
>   >   >   ```java
>   >   >   public > protected > default(包访问权限,无显式的void)> private
>   >   >   
>   >   >   
>   >   >   "父类"\"子类"   public  default  protected   private
>   >   >   public         true     true      true       -
>   >   >   protected      true       -       true       -
>   >   >   default        true     true        -        -
>   >   >   private          -       -          -        -
>   >   >   
>   >   >   class A{
>   >   >     ..
>   >   >     public void ff(){  ...}
>   >   >     ..
>   >   >   }
>   >   >   class B extends A{
>   >   >     ...
>   >   >     void ff(){} //不合法,缺省的严格性比public强
>   >   >     ...
>   >   >   }
>   >   >   ```

## **6.super关键字**

#### **0.`super`的定义**

**表示或代表当前对象的直接父类对象,对当前父类对象的直接引用**

>   **使用方法:子类的`数据成员`或`方法名`与父类相同,可以使用关键字指明使用父类**
>
>   ```java
>   super.data_member
>   super.function(para)
>   super(para)
>   //(1) 用来访问直接父类隐藏的数据成员：super.数据成员
>   //(2) 用来调用直接父类中被覆盖的成员方法：super.成员方法(参数)
>   //(3) 用来调用直接父类的构造方法：super(参数) 
>   ```

#### **1.构造方法的继承**

###### **原则**

**子类可以继承父类的`构造方法`,遵循以下原则:**

1.   **子类无条件继承父类的`不含参数的构造方法`**
2.   **子类自己没有构造方法,继承父类的无参数构造方法作为自己的构造方法**
3.   **子类有自己的构造方法,先继承父类的无参数构造方法,再执行自己的构造方法**
4.   **父类含参数构造方法,子类通过自己的构造方法``"的第一句话"``中调用`super`来调用它**

>   ```java
>class A {
>       A(int x) {
>           System.out.println("父类 A 的构造方法，x = " + x);
>       }
>   }
>class B extends A {
>       B() {
>           // 这里没有显式调用 super(x)，会导致编译错误
>           System.out.println("子类 B 的构造方法");
>       }
>   }
>   class Test {
>       public static void main(String[] args) {
>           new B();  // 编译错误：子类 B 必须显式调用父类 A 的带参构造方法
>       }
>   }
>   /*
>   constructor A in class A cannot be applied to given types;
>     required: int
>     found: no arguments
>   */
>   ```
>   
>   ```java
>   class A {
>       A() {
>           System.out.println("父类 A 的无参构造方法");
>       }
>       A(int x) {
>        System.out.println("父类 A 的构造方法，x = " + x);
>       }
>   }
>   class B extends A {
>       B() {
>           // 子类 B 的构造方法没有显式调用 super()
>           System.out.println("子类 B 的构造方法");
>       }
>   }
>   class Test {
>       public static void main(String[] args) {
>           new B();  // 不需要显式调用 super()，会默认调用父类的无参构造方法
>       }
>   }
>   // 父类 A 的无参构造方法
>   // 子类 B 的构造方法
>   ```
>   

###### **区别**

>   **如果父类有一个`无参构造方法`，并且子类的构造方法没有显式调用 `super()`**
>
>   >   **流程:父类的构造方法会先被调用，然后才是子类的构造方法。**
>   
>   **如果父类只有`带参数的构造方法`，子类的构造方法必须显式调用 `super()`**
>   
>>   **`super(x);`**
>   
>   **如果父类既有`带参的构造方法`又有`不带参的构造方法`**
>   
>   >   **如果不声明`super()`,默认调用无参父类方法**

**人话:Java通过super()来从`父类->子类`**

#### **2.使用super操作被隐藏的成员变量和方法**

>   ```java
>   "子类对象"
>       子类继承的成员变量
>       子类声明的成员变量
>       子类声明或重写的方法
>       子类继承的方法
>   "super"
>       子类隐藏的成员变量 ->  访问方式:super.x
>       子类隐藏的方法    ->  访问方式:super.play()
>   ```
>
>   ```java
>   public class Average extends Sum {
>      double n; // 子类中的 double 类型变量 n
>      // 这个 n 隐藏了父类中 int 类型的变量 n
>   
>      public double f() {
>         double c;  // 声明一个局部变量 c
>         super.n = (int)n;  // 将子类中的 double 类型变量 n 强制转换为 int，赋值给父类的 int 类型变量 n
>         c = super.f();  // 调用父类的 f() 方法，将返回值赋给 c
>         return c + n;  // c + n
>      }
>   
>      public double g() {
>         double c;  // 声明一个局部变量 c
>         c = super.f();  // 调用父类的 f() 方法，将返回值赋给 c
>         return c - n;   // (c + n) - n
>      }
>   }
>   
>   ```

## **7.final 关键字**

#### **定义和目的**

**`final`关键字可以修饰类\成员变量\方法中的局部变量**

>   **`final`类不能被继承(不能有子类)**

#### **1.对常量使用`final`**

**该常量不能被修改,为最终数据成员**

**注意:在`定义赋值`和`构造函数中赋值`你只能赋值一次，并且赋值后不能再修改它的值**

**在子类构造函数可能赋值,在主类不能直接赋值`m1.nn=90`**

>   ```java
>public class Example {
>       final int x = 10;  // 直接在定义时给 final 变量赋值
>
>       public Example() {
>        // 不可以在构造函数中修改 x 的值
>           // x = 20;  // 编译错误：cannot assign a value to final variable 'x'
>    }
>   }
>   ```
>   
>   ```java
>   class ca {
>       static int n = 20;  // 静态变量 n，初始值为 20
>   
>       final int nn;  // 声明 final 变量 nn，但没有直接赋初值
>       //如果是实例变量（非静态变量），它们可以在构造函数中进行赋值。
>       final int k = 40;  // 声明并直接赋值 40 给 final 变量 k
>
>       ca() {
>           nn = ++n;  // 在构造函数中为 final 变量 nn 赋值
>           // (如果什么都不写)  // 编译错误：final 变量 nn 必须在构造函数中赋值
>       }
>   }
>   
>   ```
>   

#### **2.与`static`的结合**

>   **若类有多个对象,而某个数据成员是常量,最好将常量命名为`static`,即`static final`**
>
>   **这样做到目的是节省空间,但这时只能在定义赋值,不能再构造函数赋值**
>
>   >   ```java
>>   class A {
>   >   //final double PI; 只写成这样是合法的,可以在构造函数中赋值
>>    final double PI=3.1415926;// PI是常量
>   >    public double getArea(final double r) {
>   >       // r=89; 非法，因为不允许再改变r的值
>   >       return PI*r*r;
>   >    }
>   >    public final void speak() {
>   >       System.out.println("您好，How's everything here ?");
>   >    } 
>   >   }
>   >   class B extends A {
>   >   /* 非法，不能重写speak方法
>>    public void speak() {
>   >        System.out.println("你好");
>   >    } 
>   >    */
>   >   }
>   >   public class Example5_8 {
>   >    public static void main(String args[]) {
>   >        B b=new B();
>   >        System.out.println("面积："+b.getArea(100));
>   >        b.speak();       //调用继承的方法
>   >     }
>   >   }
>   >   
>   >   ```

## **8.对象的上传型对象**

**A类是B类的父类,用子类创建一个对象,把对象的引用放到父类的对象中**

>   ```java
>   A a;
>   B b = new B()
>   a = b;
>   // 此时称对象a是对象b的上传类对象
>   ```

**注意:**

>   **1.上传类对象不能操作子类新增成员**
>
>   **2.上传类对象可以访问子类`继承或隐藏的成员变量`\ `重写的方法`**
>
>   **3.子类重写了父类的方法以后,调用该重写方法时,调用重写后的方法**
>
>   ```java
>   // 父类 People
>   class People {
>       // People类中的成员变量
>       char m = 'P';  //子类和父类中都有一个 'm' 变量（变量隐藏）
>       // 重写的crySpeak方法
>       public void crySpeak(String message) {
>           System.out.println("People is speaking: " + message);
>       }
>   }
>   // 子类 Anthropoid
>   class Anthropoid extends People {
>       // 子类新增的成员变量
>       int n = 0;
>       // 子类新增的成员方法
>       public void computer(int a, int b) {
>        System.out.println("Computing the sum: " + (a + b));
>       }
>       // 重写父类的 crySpeak 方法
>       @Override
>       public void crySpeak(String message) {
>        System.out.println("Anthropoid is speaking:" + message);
>       }
>   }
>   public class Example5_9 {
>     public static void main(String args[]) {
>        People  people=new People(); 
>        Anthropoid monkey=people;//monkey是people的上转型对象。
>        monkey.crySpeak("I love this game");    
>        //等同于people调用重写的crySpeak方法
>         
>        //monkey.n=100;           //非法,n是子类新增的成员变量
>        //monkey.computer(12,19)  //非法,computer()是子类新增的方法
>         
>         System.out.println(monkey.m) ;    
>         //操作隐藏的m,不等同于people.m
>         System.out.println(people.m) ;       
>         //操作子类的m
>         
>         People zhang=(People)monkey;  
>         //把上转型对象强制转化为子类的对象
>         zhang.computer(55,33);                 
>         //zhang是子类的对象
>         zhang.m='T';                           /
>         //操作子类声明的成员的变量m
>         System.out.println(zhang.m) ; 
>      }
>   }
>   ```

## **9.继承与多态**

**多态性就是父类的某个方法被子类重写时,各自产生各自功能的行为**

```java
class  动物 {
   void cry() {
   }
}
class 狗 extends 动物 {
   void cry() {
      System.out.println("这是狗的叫声：汪汪...汪汪"); 
   }  
}
class 猫 extends 动物 {
   void cry() {
      System.out.println("这是猫的叫声：喵喵...喵喵..."); 
   }  
}
public class Example5_10 {
   public static void main(String args[]) { 
      动物 animal=new 狗();   //animal是狗的上转型对象
      animal.cry(); 
      animal=new 猫();        //animal是狗的上转型对象
      animal.cry();
   }
}
```

## **10.abstract类和abstract方法**

>   **用关键词`abstract`修饰的类叫做抽象类**
>
>   **用关键词`abstract`修饰的方法叫做抽象方法**

**特点:**

>   **`抽象类`中可以有`抽象方法`,可以有`非抽象方法`,可以两种都有**
>
>   **`抽象类`不能用new运算创建`抽象类的对象`**
>
>   ```java
>   abstract class A {
>      abstract int sum(int x,int y);
>      int sub(int x,int y) { 
>         return x-y;
>      }
>   }
>   class B extends A {
>      int sum(int x,int y) {   //子类必须重写父类的sum方法
>         return x+y;
>      }
>   }
>   public class Example5_11 {
>      public static void main(String args[]) {
>         B b=new B();
>         int sum=b.sum(30,20);           //调用重写的方法
>         int sub=b.sub(30,20);           //调用继承的方法
>         System.out.println("sum="+sum);
>         System.out.println("sum="+sub); 
>      }
>   }
>   ```

**作用:**

>   **只关心方法的名字\参数\类型,不关系方法体**(关注轮廓)
>
>   ```java
>   abstract class 机动车 {
>      abstract void 启动();
>      abstract void 加速();
>      abstract void 刹车();
>   }
>   class 手动档轿车 extends 机动车 {
>      void 启动() {
>         System.out.println("踏下离合器，换到一挡");
>         System.out.println("然后慢慢抬起离合器");
>      }
>      void 加速() {
>         System.out.println("踩油门");
>      }
>      void 刹车() {
>         System.out.println("踏下离合器，踏下刹车板");
>         System.out.println("然后将挡位换到一挡");
>      }
>   }
>   
>   ```

**`abstract`类与多态**

>   **关注于程序的设计上,而不用拘泥于细节**
>
>   **核心在于:使用上传类对象,调用子类重写的方法**
>
>   ```java
>   //Animal.java
>    public abstract class Animal{
>       public abstract void cry();
>       public abstract String getAnimalName();
>   }
>   
>   //Dog .java
>   public class Dog extends Animal {
>      public void cry() {
>         System.out.println("汪汪...汪汪"); 
>      }  
>      public String getAnimalName() {
>         return "狗";
>      }
>   }
>   
>   //Cat.java
>    public class Cat extends Animal {
>      public void cry() {
>         System.out.println("喵喵...喵喵"); 
>      }  
>      public String getAnimalName() {
>         return "猫";
>      }
>   }
>   ```

## **11.接口**

#### **多重继承**

**一个子类可以有多个父类,该子类可以全部或部分继承所有直接父类的成员和方法**

>   **不支持类间的多重继承,只支持单继承,想使用多继承就需要提供接口**

#### **1.接口的声明和使用**

>   **接口时一种特殊的抽象类,只包含常量和方法的定义**
>
>   ```java
>   [修饰]interface name [extends 与否]{
>       constant的成员声明
>       Abstract声明
>   }
>   // 修饰符仅有 public和默认(不写)
>   // 父接口列表:接口也有继承性,如果有一个以上的父接口,之间用逗号隔开
>   // 常量数据成员的声明:只有 public final static 和 final static
>   // 作为特殊的抽象类型,因此不能定义方法体,只能到方法名
>   // 接口的方法:默认public abstract ,可以省略
>   interface dd{
>       public final static double PI=3.14159；//constant
>       final static int a=9； //constant 
>       int SUM=100； //constant
>       public abstract void ff(); //abstract
>       int add(int x,int y);//abstract
>   }
>   // 接口的继承性2:接口之间也可以继承,也是使用extends方法
>   ```
>

###### **抽象类的实现方法:`implement`关键字**

>   ```java
>// 先抽象后补充
>   class ddclass implements dd{
>    	void f1(){System.out.println(SUM);}
>    	public void ff(){System.out.println("ddddd");}
>    	public int add()int x,int y){retyurn x+y;}
>   }
>   
>   // 边抽象边补充
>   abstract class ddclass2 implements dd{
>    	void f1(){System.out.println(SUM);}
>   	public void ff(){System.out.println("ddddd");}
>   	public int add()int x,int y){retyurn x+y;}
>    }
>    ```
>    

###### **(创建接口)注意事项**

>   **1.接口使用关键字`interface`,不是`abstract`,也不是`class`**
>
>   **2.接口中定义的数据成员全是`final static`,即常量**
>   
>    **3.接口没有自身的构造方法,所有的方法都是抽象的**
>    
>   **4.接口的继承性,既在父子,也在接口间**

###### **(调用接口)注意事项**

>   **1.调用`implement`关键字即可调用接口,如果有多接口,中间相隔逗号**
>
>   **2.实现某接口的类不是`abstract`,那么它必须提供有关接口所有抽象方法的实现**
>   
>    >   ```java
>    >   interface Animal {
>   >      void speak();  // 抽象方法：没有方法体
>   >      void eat();    // 抽象方法：没有方法体
>   >   }
>   >   class Dog implements Animal {  // 实现接口 Animal
>   >      @Override
>   >      public void speak() {
>   >          System.out.println("Woof! Woof!");
>    >      }
>    >   
>    >      @Override
>    >      public void eat() {
>    >          System.out.println("Dog is eating...");
>   >      }
>   >   }
>   >   
>>   class Dog implements Animal {  // 实现接口 Animal
>   >      @Override
>>      public void speak() {
>   >          System.out.println("Woof! Woof!");
>   >      }
>   >      // !!错误：没有实现 eat() 方法，编译错误
>    >   }
>   >   
>    >   ```
>   >
>   >   **3.如果接口都是抽象类,所有的抽象方法必须都要实现!!**
>   >
>   >   **4.接口的抽象方法如果指定为`public`,实现方法时,`必须显式使用public`**
>    >
>    >   >   **否则会被系统警告减小了接口的访问范围**
>   >   >
>   >   >   ```java
>   >   >   interface Animal {
>>   >       public void speak();  // 接口中的方法是 public
>   >   >   }
>>   >   
>   >   >   class Dog implements Animal {
>   >   >       @Override
>   >   >       // public void speak() {  // 实现时使用 public
>   >   >       void speak() {  // 错误：没有使用 public，编译时会警告
>   >   >           System.out.println("Woof! Woof!");
>   >   >       }
>   >   >   }
>>   >   
>   >   >   ```

#### **2.理解接口**

>   **接口可以增加很多类需要的功能\不同类可以实现相同的接口\同一个类可以有多个接口**
>
>   **接口只关心操作,不关心具体实现**
>
>   **接口主要在可以增加很多功能,相同接口不一定有继承关系**

#### **3.接口回调**

>   **可以把 "实现某一接口的-类创建的-对象的-引用" 赋给该"接口声明的"接口变量,该接口变量可以调用被类重写的接口方法**
>
>   >   **与上传型对象调用子类的重写方法类似**
>   >
>   >   ```java
>   >   interface  ShowMessage {
>   >      void 显示商标(String s);
>   >   }
>   >   class TV implements ShowMessage {
>   >      public void 显示商标(String s) {
>   >         System.out.println(s);
>   >      }
>   >   }
>   >   class PC implements ShowMessage {
>   >      public void 显示商标(String s) {
>   >        System.out.println(s);
>   >      }
>   >   }
>   >   ```

#### **4.接口与多态**

>   **在接口中声明若干个abstract方法;使用接口进行程序设计的核心是接口回调**
>
>   ```java
>   //Advertisement.java
>   public interface Advertisement {
>         public void showAdvertisement();
>         public String getCorpName();
>   }
>   //AdvertisementBoard.java 
>   public class AdvertisementBoard {
>      public void show( Advertisement adver) {
>          System.out.println("广告牌显示"+adver.getCorpName()+"公司的广告词：");
>          adver.showAdvertisement();  // 回调：调用实现了接口的方法
>      }
>   }
>   /*
>   AdvertisementBoard 类通过接口 Advertisement 提供的回调方法，
>   调用实际实现了该接口的类的方法。
>   也就是说，AdvertisementBoard 并没有实现广告的具体展示内容，
>   而是依赖于外部实现了 Advertisement 接口的对象来提供具体的广告展示行为。
>   这种方式实现了高内聚低耦合，AdvertisementBoard 只知道 Advertisement 接口，
>   而不关心其实现类。
>   */
>   public class NikeAdvertisement implements Advertisement { //实现接口
>       public void showAdvertisement() {
>           System.out.println("Just Do It!");
>       }
>   
>       public String getCorpName() {
>           return "Nike";
>       }
>   }
>   
>   public class AppleAdvertisement implements Advertisement { //实现接口
>       public void showAdvertisement() {
>           System.out.println("Think Different.");
>       }
>   
>       public String getCorpName() {
>           return "Apple";
>       }
>   }
>   
>   public class Main {
>       public static void main(String[] args) {
>           Advertisement nikeAd = new NikeAdvertisement();  // 实现了Advertisement接口
>           Advertisement appleAd = new AppleAdvertisement();  // 实现了Advertisement接口
>   
>           AdvertisementBoard board = new AdvertisementBoard();
>           board.show(nikeAd);  // 回调，显示 Nike 广告
>           board.show(appleAd);  // 回调，显示 Apple 广告
>       }
>   }
>   
>   ```



**总结:**

>   **1.`abstract`类和接口,都可以有`abstract`方法**
>
>   **2.接口只能由常量不能有变量,`abstract`两者都可以有**
>
>   **3.`abstract`类可以有非`abstract`方法,接口不可以**
>
>   ```txt
>    1．继承是一种由已有的类创建新类的机制。
>       利用继承，我们可以先创建一个共有属性的一般类，根据该一般类再创建具有特殊属性的新类。
>    2．所谓子类继承父类的成员变量作为自己的一个成员变量，就好像它们是在子类中直接声明一样，
>       可以被子类中自己声明的任何实例方法操作。
>    3．所谓子类继承父类的方法作为子类中的一个方法，就像它们是在子类中直接声明一样，
>       可以被子类中自己声明的任何实例方法调用。
>    4．多态是面向对象编程的又一重要特性。 
>        子类可以体现多态，即子类可以根据各自的需要重写的父类的某个方法，
>        子类通过方法的重写可以把父类的状态和行为改变为自身的状态和行为。
>        接口也可以体现多态，即不同的类在实现同一接口时，可以给出不同的实现手段。
>    5．在使用多态设计程序时，要熟练使用上转型对象或接口回调，
>       以便体现程序设计所提倡的“开-闭”原则.
>   
>   ```
>

****

## **Homework**

```java
interface Ap {
    double f(double x, double y);
}

class Bp implements Ap {
    // 实现接口 Ap 中的 f 方法
    public double f(double x, double y) {
        return x * y;
    }

    // 定义一个普通的 g 方法
    public int g(int a, int b) {
        return a + b;
    }
}

public class Main {
    public static void main(String[] args) {
        // 创建 Ap 接口的对象，并通过 Bp 实现类进行实例化
        Ap a = new Bp();
        // 调用 f 方法
        System.out.println(a.f(3, 5));  // 输出：15.0
        // 强制类型转换，将 Ap 类型的对象转换为 Bp 类型
        Bp b = (Bp) a;
        // 调用 Bp 类中的 g 方法
        System.out.println(b.g(3, 5));  // 输出：8
    }
}
//15.0  // 这是 f(3, 5) 的结果，x * y = 3 * 5 = 15.0
//8     // 这是 g(3, 5) 的结果，a + b = 3 + 5 = 8

interface Com{
    int add(int a,int b);
}
abstract class Abs{
    abstract int add(int a,int b);
}
class  Bbs extends Abs implements Com{
    public int add(int a,int b){
        return a+b;
    }
}
public class Main {
    public static void main(String[] args) {
        Bbs b = new Bbs();
        Com com = b;
        System.out.println(com.add(12,6));
        Abs a = b;
        System.out.println(a.add(10,5));
    }
}
// 18
// 15
```