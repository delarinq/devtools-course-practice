// Copyright 2021 Novozhilova Ekaterina

#include "include/matrix_operations.h"
#include "include/matrix_operations_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

MyApplication::MyApplication() : message_("") {}

void MyApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a matrix calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname +
          " <number of rows of original matrix>" +
          " <number of columns of original matrix" +
          " <original matrix's elements>" +
          " <specify type of the second argument: " +
          "<number> or <matrix> or <none>" +
          " <number of elements if matrix and one number " +
          "if number and nothing if none>" +
           " <operation>\n\n" +

          "<operation> is one of the listed:\n " +
          "'*' for both matrix-number and matrix-matrix\n " +
          "'+' for two matrices\n " +
          "'/' for matrix and number\n " +
          "'-' for two matrices\n " +
          "'transpose' for a single matrix\n " +
          "'determinant' for a single matrix\n " +
          "'inverse' for a single matrix\n";
}

bool MyApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        int or_rows_  = std::atoi(argv[1]);
        int or_cols_  = std::atoi(argv[2]);
        unsigned int or_rows = static_cast<unsigned int>(or_rows_);
        unsigned int or_cols = static_cast<unsigned int>(or_cols_);
        unsigned int first_arg_num = or_rows * or_cols + 3;
        unsigned int supp_argc = 0;
        unsigned int argc_uns = static_cast<unsigned int>(argc);
        if ((or_rows == 0) || (or_cols == 0)) {
            help(argv[0], "ERROR: Invalid dimension size.\n\n");
            return false;
        } else if (strcmp(argv[first_arg_num], "matrix") == 0) {
            int ad_rows_  = std::atoi(argv[first_arg_num + 1]);
            int ad_cols_  = std::atoi(argv[first_arg_num + 2]);
            unsigned int ad_rows = static_cast<unsigned int>(ad_rows_);
            unsigned int ad_cols = static_cast<unsigned int>(ad_cols_);
            supp_argc = first_arg_num + 1 + 2 + ad_rows * ad_cols + 1;
            if ((ad_rows == 0) || (ad_cols == 0)) {
                help(argv[0],
                "ERROR: Invalid dimension size of the second matrix.");
                return false;
            }
            if (supp_argc != argc_uns) {
                help(argv[0],
                "ERROR: Invalid number of arguments for the second matrix.");
                return false;
            }
        } else if (strcmp(argv[first_arg_num], "number") == 0) {
            supp_argc = first_arg_num + 1 + 2;
            if (supp_argc != argc_uns) {
                help(argv[0], "ERROR: Invalid number of arguments for matrix.");
                return false;
            }
        } else if (strcmp(argv[first_arg_num], "none") == 0) {
            supp_argc = first_arg_num + 1 + 1;
            if (supp_argc != argc_uns) {
                help(argv[0], "ERROR: Invalid number of arguments for matrix.");
                return false;
            }
        }
    }
    return true;
}

std::string MyApplication::parseOperation(const char* arg) {
    if (strcmp(arg, "inverse") == 0) {
        return ("inverse");
    } else if (strcmp(arg, "transpose") == 0) {
        return ("transpose");
    } else if (strcmp(arg, "determinant") == 0) {
        return ("determinant");
    } else if (strcmp(arg, "/") == 0) {
        return ("/");
    } else if (strcmp(arg, "*") == 0) {
        return ("*");
    } else if (strcmp(arg, "+") == 0) {
        return ("+");
    } else if (strcmp(arg, "-") == 0) {
        return ("-");
    } else {
        return message_ =
        "ERROR: Invalid operation format, second type format or invalid input!";
    }
}

std::string MyApplication::parseSecondType(const char* arg) {
    if (strcmp(arg, "matrix") == 0) {
        return ("matrix");
    } else if (strcmp(arg, "none") == 0) {
        return ("none");
    } else if (strcmp(arg, "number") == 0) {
        return ("number");
    } else {
        return message_ =
        "ERROR: Invalid operation format, second type format or invalid input!";
    }
}
std::string MyApplication::operator()(int argc, const char** argv) {
    std::string s_type;
    std::vector<std::vector<double>> arr;
    std::vector<std::vector<double>> ad_arr;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    std::ostringstream stream;
    try {
        std::string op;
        double num = 0;
        int or_rows_  = std::atoi(argv[1]);
        int or_cols_  = std::atoi(argv[2]);
        unsigned int or_rows = static_cast<unsigned int>(or_rows_);
        unsigned int or_cols = static_cast<unsigned int>(or_cols_);
        unsigned int ad_rows;
        unsigned int ad_cols;

        arr.resize(or_rows);
        for (unsigned int i = 0; i < or_rows; i++) {
            arr[i].resize(or_cols);
        }
        int k = 0;
        for (unsigned int i = 0; i < or_rows; i++) {
            for (unsigned int j = 0; j < or_cols; j++) {
                arr[i][j] = std::atof(argv[3 + k]);
                k++;
            }
        }
        int type_ind = or_rows * or_cols + 3;
        s_type = parseSecondType(argv[type_ind]);
        if (s_type == "matrix") {
            int ad_rows_  = std::atoi(argv[type_ind + 1]);
            int ad_cols_  = std::atoi(argv[type_ind + 2]);
            ad_rows = static_cast<unsigned int>(ad_rows_);
            ad_cols = static_cast<unsigned int>(ad_cols_);
            ad_arr.resize(ad_rows);
            for (unsigned int i = 0; i < ad_rows; i++) {
                ad_arr[i].resize(ad_cols);
            }
            for (unsigned int i = 0; i < ad_rows; i++) {
                k = 0;
                for (unsigned int j = 0; j < ad_cols; j++) {
                    ad_arr[i][j] = std::atof(argv[type_ind + 3 + k]);
                    k++;
                }
            }
            op = parseOperation(argv[type_ind + 3 + ad_rows * ad_cols]);
        } else if (s_type == "number") {
            num = std::atof(argv[type_ind + 1]);
            op = parseOperation(argv[type_ind + 2]);
        } else if (s_type == "none") {
            op = parseOperation(argv[type_ind + 1]);
        } else { return s_type; }

        Matrix m_1(or_rows, or_cols);
        m_1.set_data(arr);
        Matrix m_2(1, 1);
        if (s_type == "matrix") {
            Matrix tmp(ad_rows, ad_cols);
            tmp.set_data(ad_arr);
            m_2 = tmp;
        }

        Matrix res_m(1, 1);
        double res_num;
        unsigned int res_rows;
        unsigned int res_cols;
        if (op == "+") {
            std::cout << "OK "<< std::endl;
            if ((or_rows != ad_rows) || (or_cols != ad_cols)) {
                return message_ =
                "ERROR: Invalid matrix sizes for the current operation.";
            }
            res_m = m_1 + m_2;
            res_rows = res_m.Get_Rows();
            res_cols = res_m.Get_Cols();
            stream << "Res is " << std::endl;
            for (unsigned int i = 0; i < res_rows; i++) {
                for (unsigned int j = 0; j < res_cols; j++) {
                    stream << res_m[i][j] << " ";
                }
                stream << std::endl;
            }
        } else if (op == "*") {
            if (s_type == "number") {
                res_m = m_1 * num;
            } else if (s_type == "matrix") {
                if ((or_rows != ad_cols) || (or_cols != ad_rows)) {
                    return message_ =
                    "ERROR: Invalid matrix sizes for the current operation.";
                }
                res_m = m_1 * m_2;
            }
            res_rows = res_m.Get_Rows();
            res_cols = res_m.Get_Cols();
            stream << "Res is " << std::endl;
            for (unsigned int i = 0; i < res_rows; i++) {
                for (unsigned int j = 0; j < res_cols; j++) {
                    stream << res_m[i][j] << " ";
                }
                stream << std::endl;
            }
        } else if (op == "-") {
            res_m = m_1 - m_2;
            res_rows = res_m.Get_Rows();
            res_cols = res_m.Get_Cols();
            for (unsigned int i = 0; i < res_rows; i++) {
                for (unsigned int j = 0; j < res_cols; j++) {
                    stream << res_m[i][j] << " ";
                }
                stream << std::endl;
            }
        } else if (op == "/") {
            res_m = m_1 / num;
            res_rows = res_m.Get_Rows();
            res_cols = res_m.Get_Cols();
            for (unsigned int i = 0; i < res_rows; i++) {
                for (unsigned int j = 0; j < res_cols; j++) {
                    stream << res_m[i][j] << " ";
                }
                stream << std::endl;
            }
        } else if (op == "transpose") {
            res_m = m_1.Get_Transpose();
            res_rows = res_m.Get_Rows();
            res_cols = res_m.Get_Cols();
            stream << "Res is " << std::endl;
            for (unsigned int i = 0; i < res_rows; i++) {
                for (unsigned int j = 0; j < res_cols; j++) {
                    stream << res_m[i][j] << " ";
                }
                stream << std::endl;
            }
        } else if (op == "determinant") {
            res_num = m_1.Determinant();
            stream << "Determinant is " << res_num << std::endl;
        } else if (op == "inverse") {
            m_1.Inverse();
            res_rows = m_1.Get_Rows();
            res_cols = m_1.Get_Cols();
            stream << "Res is " << std::endl;
            for (unsigned int i = 0; i < res_rows; i++) {
                for (unsigned int j = 0; j < res_cols; j++) {
                    stream << m_1[i][j] << " ";
                }
                stream << std::endl;
            }
        } else {
            return op;
        }
    }
    catch(...) {
        help(argv[0]);
        return message_ = "ERROR: Invalid input";
    }

    message_ = stream.str();

    return message_;
}
