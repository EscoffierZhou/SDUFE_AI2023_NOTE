<img src="https://counter.seku.su/cmoe?name=hiiragi_ansuke_learning&theme=r34"/>

# **10 Java Swing**

**<font color=red>(期末考试最后一个大题,必考)</font>**

```java
import javax.swing.*; // 框架包
import java.awt.*; // 框架位置包
import java.awt.event.*; // 行为事件包

class Win extends JFrame implements ActionListener {
    JLabel b1 = new JLabel("one");
    JLabel b2 = new JLabel("two");
    JLabel b3 = new JLabel("result");
    JTextField tf1 = new JTextField(10);
    JTextField tf2 = new JTextField(10);
    JTextField tf3 = new JTextField(10);
    JButton btn1 = new JButton("compute");
    JButton btn2 = new JButton("clear");
    //JCheckBox c =new JCheckBox("read");//不讲不考(打勾的框)

    Win(String S) {
        //this.add("North",b1);
        setLayout(new FlowLayout());
        add(b1);
        add(tf1);
        add(b2);
        add(tf2);
        add(b3);
        add(tf3);
        add(btn1);
        add(btn2);
        btn1.addActionListener(this); // 因为当前的类实现了这个接口(对象)
        btn2.addActionListener(this);
        tf3.setEditable(false); // 结果框不可编辑
        // super(s);//子类调用父类,第一行
        setTitle(S); // 设置窗口标题
        setLocation(300, 300); // 设置窗口位置
        // 必不可少的函数,必考

        setSize(400, 400); // 设置窗口大小
        setVisible(true); // 显示窗口
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 设置关闭操作
    }

    public void actionPerformed(ActionEvent e) { // 交互式处理
        if (e.getSource() == btn1) {
            //b1.setText("Aaaaaaaaaaaaaaaa"); // 反馈信息
            String s1 = tf1.getText(); // 获取第一个文本框的内容
            String s2 = tf2.getText(); // 获取第二个文本框的内容
            try {
                // 将字符串转换为double类型
                double m = Double.parseDouble(s1);
                double n = Double.parseDouble(s2);
                double sum = m + n;
                tf3.setText(String.valueOf(sum));//设置结果框的值
                //方法1: ""+sum
                //方法2: String.ValueOf(sum)
            } catch (Exception e1) {
                // 异常捕获，输出错误信息
                System.out.println("error");
            }
        }
        if (e.getSource() == btn2) {
            tf1.setText(""); // 清空第一个文本框
            tf2.setText(""); // 清空第二个文本框
            tf3.setText(""); // 清空结果框
            // 或者tf1.setText(null);
        }
    }
}

public class Main {
    public static void main(String args[]) {
        new Win("Hello"); // 创建窗口
    }
}

```

## **流程**

1.直接调用Jframe或者继承子类,创建窗口(要导入包)

2.Jframe默认不可见,大小(0,0),所以先构造方法(setSize(400,400)),并且设置可视化visible->(Main函数调用win()可查看一个表)

3.创建窗口名,构造函数/setTitle两种方法

4.调用`setDefaultCloseOperation`使得窗口关闭以后也要中断进程(不然JDK无法运行其它程序)

5.窗口是默认左上角(0,0),设置窗口到屏幕中心位置

6.加东西

>   1.加标签(标签类)
>
>   >   1.初始化标签
>   >
>   >   2.放到win之中,add方法
>   >
>   >   3.由于布局方法,多个标签会被覆盖,所以需要调整不同标签的位置
>   >
>   >   >   1.BorderLayout:修改add参数,注意首字母大写(不美观不方便)
>   >
>   >   >   2.setLayout:在add之前修改布局,流水线式修改布局(居中布局,一行一行布局,从左到右,不够下一行)->调用包`java.awt.*`
>
>   2.加文本框(`JTextField`)
>
>   >   调用包,并且设置输入文本框的长度
>   >
>   >   修改文本框的功能(输入不用设置,但是输出结果不可修改,修改`Editable`)
>
>   3.加按钮
>
>   >   1.初始化
>   >
>   >   2.放到Swing界面中

7.界面完成后,实现功能(事件处理机制)

>   1.添加行为事件`ActionEvent`的方法`actionPerformed`(变量名不能更改)
>
>   >   **行为事件方法必须满足两个条件:**
>   >
>   >   **1.事件来自一个接口`ActionListener`->所以修改class后面激活该组件(抽象方法)**
>   >
>   >   **2.行为事件的注册:需要在类的构造方法中的某个地方进行注册**
>
>   2.在行为事件中修改反馈信息:点一次运行一次(每个组件都可以加反馈信息)
>
>   >   **在其中获取数据->计算数据->转换数据->输出文本**
>
>   3.拓展行为事件的个数`getsource`
>
>   >   1.输入数据,输出相加后的结果
>   >
>   >   2.clear删除目前

8.异常处理

>   1.未输入内容:`NumberFormatException`
>
>   2.无法转换为整数:输入小数->修改为double类

9.可视化优化

>`getActionCommand`可以看清楚按钮的功能,而不是一味地修改btn1

***

Eg2:this的使用

```java
package pp1;

import javax.swing.*;//框架包
import java.awt.*; // 框架位置包
import java.awt.event.*;//行为事件包

class win extends JFrame implements ActionListener{
    Jlabel b1 = new Jlabel("one");
    Jlabel b2 = new Jlabel("two");
    Jlabel b3 = new Jlabel("result");
    JTextField tf1 = new JTextField(10);
    JTextField tf2 = new JTextField(10);
    JTextField tf3 = new JTextField(10);
    JButton btn1 = new JButton("compute");
    JButton btn2 = new JButton("clear");
    //JCheckBox c =new JCheckBox("read");//不讲不考(打勾的框)
    win(String S){
        //this.add("North",b1);
        setLayout(new FlowLayout());
        add(b1);
        add(tf1);
        add(b2);
        add(tf2);
        add(b3);
        add(tf3);
        add(btn1);
        add(btn2);
        btn1.addActionListener(new inner()); //因为当前类的内部类inner实现了这个接口(对象)
        btn2.addActionListener(new inner()); 
        tf3.setEditable(false);
        // super(s);//子类调用父类,第一行
        setTitle(s); //使用Frame方法
        setLocation(300,300); // 设置窗口在中心的位置
        // 必不可少的函数,必考
        this.setSize(400,400);//弹出的默认大小,可拖动
        this.setVisible(true);;
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    class inner implements ActionListener{  //使用内部类:可以使用类的成员变量
         public void actionPerformed(ActionEvent e){ //交互式
            if (e.getSource()==btn1){
                //b1.setText("Aaaaaaaaaaaaaaaa"); // 反馈信息
                String s1 = tf1.getText(); // 返回值string "12 "
                String s2 = tf1.getText(); // 返回值string "34 "
                try{
                    double m = double.pareDouble(s1);  //修改为double
                    double n = double.pareDouble(s1);  //修改为double
                    double sum = m+n;  
                    tf3.setText(""+sum); //输入的是字符串,数据还要转换
                    //方法1: ""+sum
                    //方法2: String.ValueOf(sum)
                }catch(Exception e1){ 
                    //提示信息
                    System.out.prinln("error");
                }
            }
            if ((e.getActionCommand()).equals("clear")){  // getActionCommand可以看清楚按钮的功能
                tf1.setText("");
                tf2.setText("");
                tf3.setText("");
                // 或者tf1.setText(null);
            }
    	}  
    }
}

public class project {
    public static void main(String args[]){
        new win("Hello");
    }
}
```

**心得:**

定义变量的时候只能在类中,如果放到类的方法中会变成局部变量

写代码必须放到一个方法里面(类创建对象必须调用构造方法)

所有类都继承一个object的父类

 
