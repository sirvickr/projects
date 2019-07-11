// Материалы из последней лекции (неделя 1)

typedef struct _object {
	_PyObject_HEAD_EXTRA
	Py_ssize_t ob_refcnt;
	struct _typeobject *ob_type;
} PyObject;

typedef struct {
	PyObject ob_base;
	Py_ssize_t ob_size; // Кол-во элементов в переменной части
} PyVarObject;

#define PyObject_HEAD PyObject ob_base;
#define PyObject_VAR_HEAD PyVarObject ob_base;

/*
typedef struct PyMyObject {
	PyObject_HEAD
	...

или

typedef struct PyMyObject {
	PyObject_VAR_HEAD
		...
*/
