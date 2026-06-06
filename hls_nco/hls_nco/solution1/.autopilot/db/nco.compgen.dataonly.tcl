# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_AXILiteS {
sine_sample_V { 
	dir O
	width 16
	depth 1
	mode ap_vld
	offset 16
	offset_end 23
}
step_size_V { 
	dir I
	width 16
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
}
dict set axilite_register_dict AXILiteS $port_AXILiteS


