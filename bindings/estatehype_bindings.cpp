#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "api_integration.h"

namespace py = pybind11;

PYBIND11_MODULE(estatehype, m) {
    m.doc() = "Python bindings for EstateHype";

    py::class_<APIIntegration>(m, "APIIntegration")
        .def(py::init<>())
        .def("fetch_data", &APIIntegration::fetchData)
        .def("fetch_data_multithreaded", &APIIntegration::fetchDataMultithreaded);
}
