module BitBrick(
    input clk,          // 新增时钟信号
    input [1:0] a,
    input [1:0] b,
    input s_a,
    input s_b,
    output   [3:0] product  // 改为寄存器输出
);

reg [2:0] a_ext, b_ext;
reg [5:0] temp_product;

always @(posedge clk) begin
    // 符号扩展
    a_ext[2] <= s_a & a[1];
    a_ext[1:0] <= a[1:0];
    
    b_ext[2] <= s_b & b[1];
    b_ext[1:0] <= b[1:0];
    
    // 有符号乘法
    temp_product <= $signed(a_ext) * $signed(b_ext);
    
    // 输出结果
    
end
  assign product = temp_product[3:0];
endmodule


