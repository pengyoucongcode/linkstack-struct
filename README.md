# linkstack-struct
## Expalin
* This program realizes the simple operation of linked list, such as create, sort, display, merge linked list, search (by address and by value), delete (by value and address) and insert operation.
* In my test plan, I used two arrays to create linked lists LA and LB, using different linked list creation functions (CreateLA and CreateLB), and then used MergeLists to merge the two linked lists into LC.
* Then do the following:
1) find the location of the given element in the LC (such as 65) and display it on the screen 
2) find the value of the location given in the LC (such as the fifth element) and display it on the screen 
3) delete the given in the LC A value (such as 82)
4) removes the value of the given position (that is, the number of elements) in the LC.
5) display the data of LC after the previous operation is completed. 
6) insert the number 55, 43 into the LC, while keeping the data in descending order in the LC, and then display all the data in the LC on the screen. 
7) insert any number of integers into the LA,LB table, and note that the data in LA and LB is still in descending order. Then update the LC and display the contents of the updated table LC.
* The results of the program run are as follows
```
LA:78 64 37 30 29 24 18 12 9 2
当前线性表长度：10
LB:93 82 73 65 44 35 31 28 26 17 15
当前线性表长度：11
LC:93 82 78 73 65 64 44 37 35 31 30 29 28 26 24 18 17 15 12 9 2
当前线性表长度：21
以下是线性表LC的操作：
请输入你想查找的值：82
82在线性表中的位置是：2
请输入索引值:5
第5位的数据值是65
请输入你想从线性表中删除的数值：73
LC:93 82 78 65 64 44 37 35 31 30 29 28 26 24 18 17 15 12 9 2
当前线性表长度：20
输入你想从线性表删除的位置：5
LC:93 82 78 65 44 37 35 31 30 29 28 26 24 18 17 15 12 9 2
当前线性表长度：19
输入你想插入线性表的数值个数：2
请逐个输入你想插入线性表中的数值：14 50
LC:93 82 78 65 50 44 37 35 31 30 29 28 26 24 18 17 15 14 12 9 2
当前线性表长度：21
LA进行插值输入你想插入线性表的数值个数：1
请逐个输入你想插入线性表中的数值：27
新LA:78 64 37 30 29 27 24 18 12 9 2
当前线性表长度：11
LB进行插值输入你想插入线性表的数值个数：1
请逐个输入你想插入线性表中的数值：100
新LB:93 82 73 65 44 35 31 28 26 17 15 100
当前线性表长度：12
新LC:100 93 82 78 73 65 64 44 37 35 31 30 29 28 27 26 24 18 17 15 12 9 2
当前线性表长度：23
```
