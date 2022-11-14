# C

### Answers

#### 1.
![Image1](https://github.com/TimonLevy/Programming-Languages/blob/5004e38554d474532f2f20437d505e987e242198/C/Ex1.png)
![image2](https://github.com/TimonLevy/Programming-Languages/blob/5004e38554d474532f2f20437d505e987e242198/C/Ex2.png)
```
In the solution above we have a code snipet and it's execution's results.
The code recieves a char or a string and prints 0 if they are not equal to EOF or 1 if they are.

In the first input we see 'A' followed by two zeros, that is because the input is actually "A\n". The program recognizes that
and prints two zeros because neither 'A' nor '\n' are EOF.

In the second attempt we see a black line, that s because the input was '\n', which is not an EOF char so it printed 0 once.

In the last attempt and sigint was sent (^Z or Ctrl + Z) which is an EOF char and the program prompted 1 correctly.

Hence when given normal characters (getchar() == EOF) would print 0, and when given EOF it would print one. If the operator was to be != then the result would be inverted.
```

#### 10.

| No.   | Allergy           |
| --    | --                |
|       | **Nuts**          |
| 1     | Walnuts           |
| 2     | Pecans            |
| 3     | Peanuts           |
| 4     | Pine Nut          |
|       | **Fruit**         |
| 5     | Melon             |
| 6     | Watermelon        |
| 7     | Kiwi              |
| 8     | Dragonfruit       |
| 9     | Avocado           |
|       | **Miscellaneous** |
| 10    | MSG               |
| 11    | Mold              |
| 12    | 7 types of grass  |
| 13    | Dust              |