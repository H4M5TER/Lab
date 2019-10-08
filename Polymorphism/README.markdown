# 多态

## Polymorphism

From [Wikipedia](https://en.wikipedia.org/wiki/Polymorphism_%28computer_science%29)

> polymorphism is the provision of a single interface to entities of different types or the use of a single symbol to represent multiple different types.

多态即对不同类型的实现提供相同的接口，或使用相同的符号来表现多种不同的类型。  
多态并不是单纯的OOP概念，早在其诞生之前便已存在。

### OOP Subtyping Override

OOP中的多态是多态的一种，维基百科上称为Subtyping。  
我们常用子类重写(Override)父类的虚函数，然后仍然通过父类的接口去使用它，这即为Subtyping。

### Ad hoc polymorphism Overload

除此之外，普通的函数重载(Overload)也是一种多态，称为特定(ad hoc)多态。  
向一个相同的函数传递不同的参数以使用不同实现即为Ad hoc polymorphism。

### Parametric polymorphism Generics

C++中的模板(Template)也是多态的一种，参数化(Parametric)多态。  
通过模板，我们不需要在乎参数的类型，可以总是使用相同的实现。
其他语言中的泛型(Generics)等也是如此。

### Review

综上，多态可以简单地理解为函数在不同情况有不同的(或相同的)实现。  
当然，我也可以在代码中通过ifelse等来实现相同的情况。  
那么，多态的共同点是什么呢。

## Dispatch

答案很简单，多态的机制都是编译器在编译时和程序在运行时对函数进行分派(Dispatch)，由编译器来决定使用哪种实现。  
这其中还分几种情况：

### Static / Dynamic

动态(Dynamic)分派生效于运行时，在运行时，程序通过虚函数表分派子类重写(Override)过的函数。  
这是我们通常所说的多态(Subtyping)使用的实现。

静态(Static)分派生效于编译时，编译器通过方法签名、参数、接收者(属于的对象的类型)来分派函数。  
函数重载(Overload)和泛型(Generics)都是在编译时静态分派的。

### Single / Multiply

(在编译时或运行时)只根据方法的接收者(属于的对象的类型)进行分派叫做单分派。  
这是我们通常所说的多态(Subtyping)使用的实现。

除了根据方法的接收者，还根据其参数等进行分派，叫做多分派。
函数重载(Overload)和泛型(Generics)属于多分派。

## Reference

<https://en.wikipedia.org/wiki/Polymorphism_(computer_science)>
<https://baike.baidu.com/item/多分派/14923408>

## TODO

查阅资料，编辑分派相关的条目。  
<https://segmentfault.com/a/1190000020391828>
<https://www.cnblogs.com/youxin/archive/2013/05/25/3099016.html>

## Edit

2019/10/08 21:33
