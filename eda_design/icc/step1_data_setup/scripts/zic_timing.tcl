set_zero_interconnect_delay_mode true
redirect -tee zic.timing { report_timing }
set_zero_interconnect_delay_mode false

report_timing -delay max -max_paths 10 -slack_less 0 -nosplit > setup_violation.rpt

report_timing -delay min -max_paths 10 -slack_less 0 -nosplit > hold_violation.rpt
