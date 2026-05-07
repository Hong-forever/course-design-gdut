# IC Compiler run script for ORCA_floorplanned

open_mw_lib F_PE.mw
open_mw_cel floorplan_complete

source scripts/opt_ctrl.tcl

# set_dont_touch_placement [all_macro_cells]

report_ignored_layers
report_pnet_options

printvar physopt_hard_keepout_distance
printvar placer_soft_keepout_channel_width

source scripts/ndr.tcl

check_physical_design -stage pre_place_opt
check_physical_constraints

# report_scan_chain
# read_def design_data/ORCA_TOP.scandef
# v report_scan_chain

# report_saif
# source scripts/inputs_toggle_rate.tcl
# report_saif

# report_power_options
# set_power_options -low_power_placement true
# report_power_options

save_mw_cel -as F_PE_preplace_setup

place_opt -area_recovery -optimize_dft -power 

save_mw_cel -as F_PE_place_opt

report_congestion -grc_based -by_layer -routing_stage global

report_design -physical
report_qor
report_power

# set_power_options -dynamic true
psynopt -area_recovery -power

report_congestion -grc_based -by_layer -routing_stage global
report_design -physical
report_qor
report_power

#timing
report_timing -delay max -max_paths 10 -slack_less 0 -nosplit > setup_violation.rpt
report_timing -delay min -max_paths 10 -slack_less 0 -nosplit > hold_violation.rpt
#power
report_power -hierarchy > report_power.rpt
#area
report_area -hierarchy > report_area.rpt


save_mw_cel -as F_PE_placed

