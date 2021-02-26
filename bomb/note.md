# Bomb Lab

> By Geng Chen

Here is the note taken when i'm solving bomb lab.

## Phase 1: comparing string

easy, just string comparison.

## Phase 2: read six number

The key is `read six number`, this function receive a string containing 6 numbers and a pointer, then write these 6 integer to the given address.

Then is a loop determining whether every element is twice bigger than previous one.

Then the answer is obvious.

## Phase 3: jump between instructions

key here is `jmpq` indirect jump instruction. Please refer to https://stackoverflow.com/questions/26543029/what-is-the-jmpq-command-doing-in-this-example

my answer is to take x = 1 and y = 0x137.

## Phase 4: recursion

`func4` is a recursive function. it makes a weird *binary search*. 

first it calculate %rcx = l + (l + r) >> 1, and then make recursive binary search. 

if val = mid, return 0.
if val > mid, return `2f + 1`.
if val < mid, return `2f`.

to be honest, I donot know what is the meaning of this weird function ;-)

## Phase 5: string mapping

Simple. The meaning is input a 6 char string, then use this tring to formulate other string.

The mapping is using a map which is stored in an address and use the least significant byte to access that. 

The output string must be "flyers" and the mapping relation is listed below.

---

f: 9  i
l: f  o
y: e  n
e: 5  e
r: 6  f
s: 7  g

a: 1
b: 2
c: 3
d: 4
e: 5
f: 6
g: 7
h: 8
i: 9
j: a
k: b
l: c
m: d
n: e
o: f

## Phase 6: sorting linked list

first step, input 6 numbers, denote them as a1, a2, a3, a4, a5, a6.

first check if ai <= 6 and distinct.

then make every ai = 7 - ai

0x6032d0 start somewhat like a linked list

then it access link list in ai order and put it to %rsp + 20

the next step is rearange the linkage of linked list according to 6 numbers.

Then check whether the linked list satisfy that the previous one is greater than the latter one.
