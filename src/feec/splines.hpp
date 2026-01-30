#pragma once

#include <vector>

void eval_b_splines(double point, int degree, int span, double grid_spacing, std::vector<double>& output);
void eval_d_splines(double point, int degree, int span, double grid_spacing, std::vector<double>& output);
void eval_b_splines_struphy(const std::vector<double>& tn, int pn, double eta, int span, std::vector<double>& values);
void eval_d_splines_struphy(const std::vector<double>& tn, int pn, double eta, int span, std::vector<double>& values);
void eval_b_d_splines(double point, int degree, int span, double grid_spacing, std::vector<double>& output_b, std::vector<double>& output_d);
void eval_b_d_splines_struphy(const std::vector<double>& tn, int pn, double eta, int span, std::vector<double>& bn, std::vector<double>& bd);
