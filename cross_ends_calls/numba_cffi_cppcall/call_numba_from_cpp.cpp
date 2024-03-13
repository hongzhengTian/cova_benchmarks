#include <Python.h>
// specify the path to libpython3.11.so.1.0
// export LD_LIBRARY_PATH=/home/hongzhet/anaconda3/lib:$LD_LIBRARY_PATH
// specify the path to the cffi_interface module, which is the current directory
// export PYTHONPATH="${PYTHONPATH}:$(pwd)"
// g++ -o call_numba_from_cpp call_numba_from_cpp.cpp $(python3-config --cflags --embed --ldflags)

int main() {
    Py_Initialize();

    PyObject* pName = PyUnicode_DecodeFSDefault("cffi_interface");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "call_add");
        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject* pArgs = PyTuple_New(2);
            PyTuple_SetItem(pArgs, 0, PyFloat_FromDouble(7.0));
            PyTuple_SetItem(pArgs, 1, PyFloat_FromDouble(3.0));
            
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != nullptr) {
                printf("Result of call: %f\n", PyFloat_AsDouble(pValue));
                Py_DECREF(pValue);
            } else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr, "Call failed\n");
                return 1;
            }
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"call_add\"\n");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"cffi_interface\"\n");
        return 1;
    }
    Py_Finalize();
    return 0;
}
