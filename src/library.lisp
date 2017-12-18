(define defun (macro (name args body) (cons 'define (cons name (cons (cons 'lambda (cons args (cons body nil))) nil)))))
(define apply (macro (fn &rest args) (cons fn args)))

(defun abs (x) (if (< x 0) (- 0 x) x))

(defun foldl (proc init list) (if list (foldl proc (proc init (car list)) (cdr list)) init))
(defun foldr (proc init list) (if list (proc (car list) (foldr proc init (cdr list))) init))

(defun list (&rest items) (foldr cons nil items))
(defun reverse (lst) (foldl (lambda (a x) (cons x a)) nil lst))

(defun mapcar (fn args) (if (car args) (cons (apply fn (car args)) (mapcar fn (cdr args))) nil))

(defun append (a b) (foldr cons b a))
(defun caar (x) (car (car x)))
(defun cadr (x) (car (cdr x)))

(define quasiquote (macro (x) (if (consp x) (if (eq (car x) 'unquote) (cadr x) (if (eq (caar x) 'unquote-splicing) (list 'append (cadr (car x)) (list 'quasiquote (cdr x))) (list 'cons (list 'quasiquote (car x)) (list 'quasiquote (cdr x))))) (list 'quote x))))
