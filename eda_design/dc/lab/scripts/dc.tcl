
read_verilog {F_PE.v BitBrick.v}

current_design F_PE

link
check_design

source F_PE.con
check_timing

source F_PE.pcon


compile_ultra -spg -retime -scan 

source report.tcl

list_licenses

report_hierarchy -noleaf
 

