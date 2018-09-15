; http://www.qlcoder.com/task/75f9
; https://www.tutorialspoint.com/lisp/index.htm 主要涉及到循环和list部分
(define (gao n)
    (do ((d (do ((i (- n 1) (- i 1))
              (d '() (cons i d)))
             ((< i 0) d))
         (append (cddr d) (list (car d)))))
     ((null? (cdr d)) (car d)))
)



(display (gao 987654321))

for (i = n - 1; i < 0; --i) {
    d = (); d = (i, d)
} return d

for (d = d; append (cddr d) (list (car d)); (cdr d) is null) {
d = d[2: ].appen(d[0])
} return car d

(0, 1, 2.... 987654320)    987654320, 0, 2, 4, 6, 8, ..., 987654318