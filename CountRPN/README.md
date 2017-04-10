#### 逆波兰表达式的求解
由于操作数在操作符前面，所以我们先按顺序遍历这个表达式，遇到操作数的时候压栈，遇到操作符的时候让栈顶的两个操作数出栈进行运算，然后把运算结果压栈。最终的结果就是栈里剩下的一个value

![逆波兰表达式求解](https://github.com/iflei/Algorithms/blob/master/CountRPN/201611291025.png?raw=true)