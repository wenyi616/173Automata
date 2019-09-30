#lang racket

; question1.1
(define (myappend l1 l2)
  (if (empty? l1)
      l2
      (cons (first l1) (myappend (rest l1) l2))))


; question1.2
(define (myreverse l1)
  (if (empty? l1)
     null
     (myappend (myreverse(rest l1)) (list(first l1)))
  )
)

; question1.3
(define (add3 x)
  (+ 3 x))

(define (mymap add3 l1)
  (if (empty? l1)
      l1
      (cons (add3 (first l1)) (mymap add3 (rest l1)))))

; question1.4
; for extra credit
(define (nub l)
  (if (empty? l)
      null
  (if (mymember (first l) (rest l))
      (nub (rest l))
      (myappend (list (first l)) (nub (rest l))))))

; question2.1
; Set membership
(define (mymember a l1)
  (if (empty? l1)
      #f
        (if (equal? a (first l1))
            #t
            (mymember a (rest l1)))))

; question 2.2
; Insert element into set
(define (myinsert a l1)
  (if (mymember a l1)
      ; if a is a member of l1
      l1
      ; else add a into it
      (cons a l1)))

; question 2.3
(define (myintersection l1 l2)
  (if (empty? l2)
      null
      (if (mymember (first l2) l1)
          ; if the element is in both sets
          (myappend (list(first l2)) (myintersection l1 (rest l2)))
          (myintersection l1 (rest l2)))))


; for extra credit
; question 2.4
; Set union
(define (myunion l1 l2)
  (if (empty? l2)
      ; if l2 is empty
      l1
      ; if not insert first element into l1 and repeat
      (myunion (myinsert (first l2) l1) (rest l2))
      ))

; question 2
; helper function: substract the second list from the first
(define (mysubtract l1 l2)
  (if (empty? l2)
      l1
      (mysubtract (remove (first l2) l1) (rest l2))))

; question 2.5
; Set Difference
(define (mydiff l1 l2)
  (mysubtract l1 (myintersection l1 l2))
  )

; question 2.6
; Symmetric difference (disjunctive union)
(define (symdiff l1 l2)
  (mysubtract (myunion l1 l2) (myintersection l1 l2))
  )

; question 3.1
; Absolute value
(define (abs x)
  (if (> x 0)
      x
      (- 0 x)))

; question 3.2
; Factorial
(define (myfact a)
  (if (equal? a 1)
      ; if a = 1
      1
      ; if a > 1
      (* a (myfact(- a 1)))))

; question 3.3
(define (right-tri a b c)
  (if (equal? (* c c) (+ (* a a) (* b b)))
      #t
      #f))


; question 4.1
; Perfect Number
(define (perfect? x)
  ; reset y(the sum of factors)
  (define y 0)
  ; for loop
  (begin (for([i x])
    (if(equal? 0 i)
       null
       (if(equal? (modulo x i) 0)
          (set! y (+ y i))
          null)))
         (if(equal? y x)
            #t
            #f)))


; question 4.2
; Abundant Number
(define (abundant? x)
  ; reset y(the sum of factors)
  (define y 0)
  ; for loop
  (begin (for([i x])
    (if(equal? 0 i)
       null
       (if(equal? (modulo x i) 0)
          (set! y (+ y i))
          null)))
         (if(> y x)
            #t
            #f)))

; question 4.3
; Deficient Number
(define (deficient? x)
  ; reset y(the sum of factors)
  (define y 0)
  ; for loop
  (begin (for([i x])
    (if(equal? 0 i)
       null
       (if(equal? (modulo x i) 0)
          (set! y (+ y i))
          null)))
         (if(< y x)
            #t
            #f)))


