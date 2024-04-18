#include <Python.h>

// Funktion zur Berechnung der Summe von zwei Zahlen
static PyObject* sum_two_numbers(PyObject* self, PyObject* args) {
    int num1, num2;
    
    // Parse die Argumente von Python
    if (!PyArg_ParseTuple(args, "ii", &num1, &num2)) {
        return NULL;
    }

    // Berechne die Summe
    int result = num1 + num2;

    // Konvertiere das Ergebnis in ein Python-Objekt
    return Py_BuildValue("i", result);
}

// Methodendefinitionen
static PyMethodDef SumMethods[] = {
    {"sum_two_numbers", sum_two_numbers, METH_VARARGS, "Berechnet die Summe von zwei Zahlen."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

// Modul-Definition
static struct PyModuleDef summodule = {
    PyModuleDef_HEAD_INIT,
    "summodule",
    NULL,
    -1,
    SumMethods
};

// Modul-Initialisierungsfunktion
PyMODINIT_FUNC PyInit_summodule(void) {
    return PyModule_Create(&summodule);
}