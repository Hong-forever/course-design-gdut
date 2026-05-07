# Create corners and P/G pads
create_cell {cornerll cornerlr cornerul cornerur} pfrelr
create_cell {vss1left vss1right vss1top vss1bottom} pv0i
create_cell {vdd1left vdd1right vdd1top vdd1bottom} pvdi
create_cell {vss2left vss2right vss2top vss2bottom} pv0a
create_cell {vdd2left vdd2right vdd2top vdd2bottom} pvda

# Define corner pad locations
set_pad_physical_constraints -pad_name "cornerul" -side 1
set_pad_physical_constraints -pad_name "cornerur" -side 2
set_pad_physical_constraints -pad_name "cornerlr" -side 3
set_pad_physical_constraints -pad_name "cornerll" -side 4

# Define signal and PG  pad locations

# Left side
set_pad_physical_constraints -pad_name "pad_a_0"    -side 1 -order 1
set_pad_physical_constraints -pad_name "pad_a_1"    -side 1 -order 2
set_pad_physical_constraints -pad_name "pad_a_2"    -side 1 -order 3
set_pad_physical_constraints -pad_name "pad_a_3"    -side 1 -order 4
set_pad_physical_constraints -pad_name "vdd2left"   -side 1 -order 5
set_pad_physical_constraints -pad_name "vdd1left"   -side 1 -order 6
set_pad_physical_constraints -pad_name "vss1left"   -side 1 -order 7
set_pad_physical_constraints -pad_name "vss2left"   -side 1 -order 8
set_pad_physical_constraints -pad_name "pad_a_4"    -side 1 -order 9
set_pad_physical_constraints -pad_name "pad_a_5"    -side 1 -order 10
set_pad_physical_constraints -pad_name "pad_a_6"    -side 1 -order 11
set_pad_physical_constraints -pad_name "pad_a_7"    -side 1 -order 12
set_pad_physical_constraints -pad_name "pad_s_a"    -side 1 -order 13

# Top side
set_pad_physical_constraints -pad_name "pad_clk"    -side 2 -order 1
set_pad_physical_constraints -pad_name "pad_bw_0"   -side 2 -order 2
set_pad_physical_constraints -pad_name "pad_bw_1"   -side 2 -order 3
set_pad_physical_constraints -pad_name "vdd2top"    -side 2 -order 4
set_pad_physical_constraints -pad_name "vdd1top"    -side 2 -order 5
set_pad_physical_constraints -pad_name "vss1top"    -side 2 -order 6
set_pad_physical_constraints -pad_name "vss2top"    -side 2 -order 7
set_pad_physical_constraints -pad_name "pad_res_8"  -side 2 -order 8
set_pad_physical_constraints -pad_name "pad_res_9"  -side 2 -order 9
set_pad_physical_constraints -pad_name "pad_res_10" -side 2 -order 10
set_pad_physical_constraints -pad_name "pad_res_11" -side 2 -order 11
set_pad_physical_constraints -pad_name "pad_res_12" -side 2 -order 12
set_pad_physical_constraints -pad_name "pad_res_13" -side 2 -order 13
set_pad_physical_constraints -pad_name "pad_res_14" -side 2 -order 14
set_pad_physical_constraints -pad_name "pad_res_15" -side 2 -order 15


# Right side
set_pad_physical_constraints -pad_name "pad_b_0"    -side 3 -order 1
set_pad_physical_constraints -pad_name "pad_b_1"    -side 3 -order 2
set_pad_physical_constraints -pad_name "pad_b_2"    -side 3 -order 3
set_pad_physical_constraints -pad_name "pad_b_3"    -side 3 -order 4
set_pad_physical_constraints -pad_name "vdd2right"  -side 3 -order 5
set_pad_physical_constraints -pad_name "vdd1right"  -side 3 -order 6
set_pad_physical_constraints -pad_name "vss1right"  -side 3 -order 7
set_pad_physical_constraints -pad_name "vss2right"  -side 3 -order 8
set_pad_physical_constraints -pad_name "pad_b_4"    -side 3 -order 9
set_pad_physical_constraints -pad_name "pad_b_5"    -side 3 -order 10
set_pad_physical_constraints -pad_name "pad_b_6"    -side 3 -order 11
set_pad_physical_constraints -pad_name "pad_b_7"    -side 3 -order 12
set_pad_physical_constraints -pad_name "pad_s_b"    -side 3 -order 13

# Bottom side
set_pad_physical_constraints -pad_name "pad_res_0"  -side 4 -order 1
set_pad_physical_constraints -pad_name "pad_res_1"  -side 4 -order 2
set_pad_physical_constraints -pad_name "pad_res_2"  -side 4 -order 3
set_pad_physical_constraints -pad_name "pad_res_3"  -side 4 -order 4
set_pad_physical_constraints -pad_name "vdd1bottom" -side 4 -order 5
set_pad_physical_constraints -pad_name "vss1bottom" -side 4 -order 6
set_pad_physical_constraints -pad_name "vss2bottom" -side 4 -order 7
set_pad_physical_constraints -pad_name "vdd2bottom" -side 4 -order 8
set_pad_physical_constraints -pad_name "pad_res_4"  -side 4 -order 9
set_pad_physical_constraints -pad_name "pad_res_5"  -side 4 -order 10
set_pad_physical_constraints -pad_name "pad_res_6"  -side 4 -order 11
set_pad_physical_constraints -pad_name "pad_res_7"  -side 4 -order 12



