module BitBrick(
    input clk,          // ÐÂÔöÊ±ÖÓÐÅºÅ
    input [1:0] a,
    input [1:0] b,
    input s_a,
    input s_b,
    output   [3:0] product  // žÄÎªŒÄŽæÆ÷Êä³ö
);

reg [2:0] a_ext, b_ext;
reg [5:0] temp_product;

always @(posedge clk) begin
    // ·ûºÅÀ©Õ¹
    a_ext[2] <= s_a & a[1];
    a_ext[1:0] <= a[1:0];
    
    b_ext[2] <= s_b & b[1];
    b_ext[1:0] <= b[1:0];
    
    // ÓÐ·ûºÅ³Ë·š
    temp_product <= $signed(a_ext) * $signed(b_ext);
    
    // Êä³öœá¹û
    
end
  assign product = temp_product[3:0];
endmodule
