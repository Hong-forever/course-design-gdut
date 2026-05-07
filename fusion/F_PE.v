            

module F_PE(
    input clk,          
    input [7:0] a,
    input [7:0] b,
    input s_a,
    input s_b,
    input [1:0] bitwidth,    // 00:2-bit, 01:4-bit, 10/11:8-bit
    output  [15:0] result   
);

wire [3:0] bb_product [15:0];
reg [7:0] product_4bit [3:0];
reg [15:0] product_8bit [15:0];

reg s_a0,s_a4,s_a5,s_a12,s_a13,s_a14,s_a15;
reg s_b0,s_b1,s_b3,s_b5,s_b7,s_b11,s_b15;

reg [3:0] result_2bit;
reg [7:0] result_4bit;
reg [15:0] result_8bit;


wire [7:0] res_4bit1   = product_4bit[0] + product_4bit[1];
wire [7:0] res_4bit2   = product_4bit[2] + product_4bit[3];

wire [15:0] res_8bit1_1  = product_8bit[0]  + product_8bit[1];
wire [15:0] res_8bit2_1  = product_8bit[2]  + product_8bit[3];
wire [15:0] res_8bit3_1  = product_8bit[4]  + product_8bit[5];
wire [15:0] res_8bit4_1  = product_8bit[6]  + product_8bit[7];
wire [15:0] res_8bit5_1  = product_8bit[8]  + product_8bit[9];
wire [15:0] res_8bit6_1  = product_8bit[10] + product_8bit[11];
wire [15:0] res_8bit7_1  = product_8bit[12] + product_8bit[13];
wire [15:0] res_8bit8_1  = product_8bit[14] + product_8bit[15];

wire [15:0] res_8bit1_2  = res_8bit1_1  + res_8bit2_1;
wire [15:0] res_8bit2_2  = res_8bit3_1  + res_8bit4_1;
wire [15:0] res_8bit3_2  = res_8bit5_1  + res_8bit6_1;
wire [15:0] res_8bit4_2  = res_8bit7_1  + res_8bit8_1;

wire [15:0] res_8bit1_3  = res_8bit1_2  + res_8bit2_2;
wire [15:0] res_8bit2_3  = res_8bit3_2  + res_8bit4_2;

BitBrick    bb0(.clk(clk), .a(a[1:0]), .b(b[1:0]), .s_a(s_a0), .s_b(s_b0), .product(bb_product[0]));
BitBrick	bb1(.clk(clk),.a(a[1:0]),.b(b[3:2]),.s_a(1'b0),.s_b(s_b1),.product(bb_product[1]));
BitBrick	bb2(.clk(clk),.a(a[1:0]),.b(b[5:4]),.s_a(1'b0),.s_b(1'b0),.product(bb_product[2]));
BitBrick	bb3(.clk(clk),.a(a[1:0]),.b(b[7:6]),.s_a(1'b0),.s_b(s_b3),.product(bb_product[3]));
BitBrick	bb4(.clk(clk),.a(a[3:2]),.b(b[1:0]),.s_a(s_a4),.s_b(1'b0),.product(bb_product[4]));
BitBrick	bb5(.clk(clk),.a(a[3:2]),.b(b[3:2]),.s_a(s_a5),.s_b(s_b5),.product(bb_product[5]));
BitBrick	bb6(.clk(clk),.a(a[3:2]),.b(b[5:4]),.s_a(1'b0),.s_b(1'b0),.product(bb_product[6]));
BitBrick	bb7(.clk(clk),.a(a[3:2]),.b(b[7:6]),.s_a(1'b0),.s_b(s_b7),.product(bb_product[7]));
BitBrick	bb8(.clk(clk),.a(a[5:4]),.b(b[1:0]),.s_a(1'b0),.s_b(1'b0),.product(bb_product[8]));
BitBrick	bb9(.clk(clk),.a(a[5:4]),.b(b[3:2]),.s_a(1'b0),.s_b(1'b0),.product(bb_product[9]));
BitBrick	bb10(.clk(clk),.a(a[5:4]),.b(b[5:4]),.s_a(1'b0),.s_b(1'b0),.product(bb_product[10]));
BitBrick	bb11(.clk(clk),.a(a[5:4]),.b(b[7:6]),.s_a(1'b0),.s_b(s_b11),.product(bb_product[11]));
BitBrick	bb12(.clk(clk),.a(a[7:6]),.b(b[1:0]),.s_a(s_a12),.s_b(1'b0),.product(bb_product[12]));
BitBrick	bb13(.clk(clk),.a(a[7:6]),.b(b[3:2]),.s_a(s_a13),.s_b(1'b0),.product(bb_product[13]));
BitBrick	bb14(.clk(clk),.a(a[7:6]),.b(b[5:4]),.s_a(s_a14),.s_b(1'b0),.product(bb_product[14]));
BitBrick	bb15(.clk(clk),.a(a[7:6]),.b(b[7:6]),.s_a(s_a15),.s_b(s_b15),.product(bb_product[15]));
    
always @(posedge clk) begin
    s_a0 <= (bitwidth == 2'b00) && s_a;
    s_a4 <= (bitwidth == 2'b01) && s_a;
    s_a5 <= (bitwidth == 2'b01) && s_a;
    s_a12 <= (bitwidth[1]) && s_a;
    s_a13 <= (bitwidth[1]) && s_a;
    s_a14 <= (bitwidth[1]) && s_a;
    s_a15 <= (bitwidth[1]) && s_a;


    s_b0 <= (bitwidth == 2'b00) && s_b;
    s_b1 <= (bitwidth == 2'b01) && s_b;
    s_b3 <= (bitwidth[1]) && s_b;
    s_b5 <= (bitwidth == 2'b01) && s_b;
    s_b7 <= (bitwidth[1]) && s_b;
    s_b11 <= (bitwidth[1]) && s_b;
    s_b15 <= (bitwidth[1]) && s_b;

    product_4bit[0] <= {4'b0000,bb_product[0]};
    product_4bit[1] <= (s_b1 && b[3] && (bb_product[1] != 0)) ? {2'b11,bb_product[1],2'b00} : {2'b00,bb_product[1],2'b00};
    product_4bit[2] <= (s_a4 && a[3] && (bb_product[4] != 0)) ? {2'b11,bb_product[4],2'b00} : {2'b00,bb_product[4],2'b00};
    product_4bit[3] <= {bb_product[5],4'b0000};

    product_8bit[0] <= {12'h0,bb_product[0]};
    product_8bit[1] <= {10'h0,bb_product[1],2'h0};
    product_8bit[2] <= {8'h0,bb_product[2],4'h0};
    product_8bit[3] <= (s_b3 && b[7] && (bb_product[3] != 0)) ? {6'h3f,bb_product[3],6'h0} : {6'h0,bb_product[3],6'h0};
    product_8bit[4] <= {10'h0,bb_product[4],2'h0};
    product_8bit[5] <= {8'h0,bb_product[5],4'h0};
    product_8bit[6] <= {6'h0,bb_product[6],6'h0};
    product_8bit[7] <= (s_b7 && b[7] && (bb_product[7] != 0)) ? {4'hf,bb_product[7],8'h0} : {4'h0,bb_product[7],8'h0};
    product_8bit[8] <= {8'h0,bb_product[8],4'h0};
    product_8bit[9] <= {6'h0,bb_product[9],6'h0};
    product_8bit[10] <= {4'h0,bb_product[10],8'h0};
    product_8bit[11] <= (s_b11 && b[7] && (bb_product[11] != 0)) ? {2'h3,bb_product[11],10'h0} : {2'h0,bb_product[11],10'h0};
    product_8bit[12] <= (s_a12 && a[7] && (bb_product[12] != 0)) ? {6'h3f,bb_product[12],6'h0} : {6'h0,bb_product[12],6'h0};
    product_8bit[13] <= (s_a13 && a[7] && (bb_product[13] != 0)) ? {4'hf,bb_product[13],8'h0} : {4'h0,bb_product[13],8'h0};
    product_8bit[14] <= (s_a14 && a[7] && (bb_product[14] != 0)) ? {2'h3,bb_product[14],10'h0} : {2'h0,bb_product[14],10'h0};
    product_8bit[15] <= {bb_product[15],12'h0};



    result_2bit <= bb_product[0];
    result_4bit <= res_4bit1 + res_4bit2;
    result_8bit <= res_8bit1_3 + res_8bit2_3;

end
    assign result = bitwidth[1] ? result_8bit : 
                    bitwidth[0] ? {8'b0, result_4bit} : {12'b0, result_2bit};
endmodule

