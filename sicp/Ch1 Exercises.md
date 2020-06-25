# SICP - Chapter 1 Exercises

### Exercise 1.1:

```scheme
10
(+ 5 3 4)
(- 9 1)
(/ 6 2)
(+ (* 2 4) (- 4 6))
(define a 3)
(define b (+ a 1))
(+ a b (* a b))
(= a b)
(if (and (> b a) (< b (* a b)))
    b
    a)
(cond ((= a 4) 6)
      ((= b 4) (+ 6 7 a))
      (else 25))
(+ 2 (if (> b a) b a))
(* (cond ((> a b) a)
         ((< a b) b)
         (else -1))
   (+ a 1))
```

1. 10
2. 12
3. 8
4. 3
5. 6
6. a (a=3)
7. b (b=4)
8. 19
9. false
10. 4
11. 16 (second conditional evaluates true)
12. 6
13. 16

### Exercise 1.2

(/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 5))))) (* 3 (- 6 2) (- 2 7)))

### Exercise 1.3

```scheme
(define (f x y z)
  (+ 
   (if (> x y) (* x x) (* y y))
   (if (> y z) (* y y) (* z z))))
```

### Exercise 1.4

If b>0 it will execute (+ a b), if b is<0 it will execute (- a b) - equivalent to a + |b|

### Exercise 1.5

Applicative order evaluation will try to evaluate (p) first, which will send it in an infinite loop (as each evaluation of (p) causes another evaluation of (p) since it keeps returning itself and will never reduce to a primitive type).

A normal order evaluation will expand the test function first:

```scheme
(test 0 (p))

(if (= 0 0) 0 (p))
```

Since if conditions evaluate the conditional (= 0 0) before evaluating either of the returns, the conditional will evaluate true and 0 will be returned with (p) having never been evaluated.

### Exercise 1.6

If is a special case which evaluate the predicate _first_ and only then evaluates one of the two clauses.  New-if a 'normal' procedure, which means that each branch will be evaluated prior to passing them in to new-if as arguments.  This means that the procedure will never actually return - the guess will never actually get accepted as good enough because the 'else' branch will be called _before_ the predicate is evaluated in new-if.

### Exercise 1.7

- Very small numbers will very quickly have absolute error <0.001, even if they still have a very large relative error to the actual answer
- Very large numbers will be stored in scientific notation, so precision will be lost the larger the number gets 

```scheme
(define (good-enough? guess x)
  (= guess (improve guess x))
```

Eventually the difference in guesses will be less than the computer's precision for storing numbers - at which point the next guess will equal the current guess.  We could also do:

```scheme
(define (good-enough? guess x)
  (< (abs (- guess (improve guess x))) 0.0001))
```

Which would check if the change between the current guess and the next guess is <0.0001

### Exercise 1.8

```scheme
(define (good-enough-cube guess x)
  (< (abs (- (* guess guess guess) x)) 0.0001))

(define (improve-cube y x)
  (/ (+ (* 2 y) (/ x (* y y)))
     3))

(define (cube-iter guess x)
  (if (good-enough-cube guess x)
      guess
      (cube-iter (improve-cube guess x) x)))

(define (cube-root x)
  (cube-iter 1.0 x))
```

