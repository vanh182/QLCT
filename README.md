# QLCT
QLCT_OOP
Mô tả bài toán:
Một công ty sản xuất của Đài Loan (CONGTY) cần quản lý thông tin về việc cấp thưởng cho người lao động 
xuất sắc (NLDXS) của các bộ phận như sau:
-Chủ quản (CQ): mã số, họ tên, bộ phận và số bản kế hoạch chiến lược (KHCL) được chọn. Mỗi bản KHCL 
được chọn sẽ được cấp thưởng 50 triệu. Ngoài ra, công ty còn thưởng thêm nếu cá nhân nhiều số bản (KHCL) 
được chọn:
+ 5<=SoKHCL<=8: thưởng thêm 20 triệu
+ SoKHCL>=8: thưởng thêm 30 triệu
-Nhân viên (NV): mã số, họ tên, bộ phận, số sáng kiến kinh nghiệm. Mỗi sáng kiến kinh nghiệm sẽ được cấp 
thưởng 5 triệu, tăng 30% số tiền cấp thưởng nếu có từ 5 sáng kiến kinh nghiệm trở lên.
-Công nhân (CN): mã số, họ tên, bộ phận, điểm sản phẩm chất lượng cao trung bình (SPCLCTB), điểm chuyên 
cần. Điểm SPCLCTB tính theo thang điểm 10 và điểm chuyên cần tính theo thang điểm 100. Công nhân có 
điểm chuyên cần từ 90 điểm trở lên mới được xem xét cấp thưởng theo quy định:
+ 8.5 <= Điểm SPCLCTB<=9: thưởng 1.5 triệu/tháng
+ Điểm SPCLCTB>9: thưởng 2.5 triệu/ tháng
Yêu cầu:
1. Vẽ sơ đồ cấu trúc phân cấp (sơ đồ phả hệ) cho các lớp. 
2. Định nghĩa các lớp để quản lý theo yêu cầu của công ty. 
3. Xây dựng các phương thức xử lý cho các lớp trên. (có kiểm tra mã số bị trùng khi nhập vào, nếu trùng sẽ
thông báo cho người dùng biết và xóa đi phần tử có mã số bị trùng)
4. Liệt kê d/s các CQ có 8 bản KHCL được chọn trở lên. 
5. Đếm số lượng các CN có điểm chuyên cần (DCC) tối đa. 
6. Tính tổng tiền cấp thưởng cho các NV có 5 sáng kiến kinh nghiệm(SKKN) trở lên. 
7. Tính điểm SPCLCTB của các CN có điểm chuyên cần dưới 50. 
8. Kiểm tra công ty có CQ nào chưa có bản KHCL được chọn không? 
9. Tìm các NV có số sáng kiến kinh nghiệm nhiều nhất. 
10. Sắp xếp d/s các NLDXS tăng dần theo mã số. 
11. Tìm kiếm NLDXS theo: mã số, họ tên, bộ phận, tiền thưởng. 
12. Cập nhật thông tin NLDSX có mã số do người dùng nhập vào. 
13. Thêm 1 NLDXS mới. 
14. Xóa 1 NLDXS có mã số do người dùng nhập vào. 
15. Xóa toàn bộ d/s NLDXS. 
16. Tạo file. 
17. Đọc file. 
18. Đọc file và lưu d/s NLDXS. 
19. Lưu file d/s NLDXS.
    Bài làm
   Vẽ sơ đồ cấu trúc phân cấp (sơ đồ phả hệ) cho các lớp.
   
   ![image](https://github.com/vanh182/QLCT/assets/118065256/1f791787-50ec-4fa2-84e1-8b7bb0601145)
   
   Chương trình sau khi hoàn thiện:
   
   ![image](https://github.com/vanh182/QLCT/assets/118065256/7b544ade-1946-4e86-acc9-f5351a23542d)
   

   


