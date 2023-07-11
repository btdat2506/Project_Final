Giả sử quy tắc tổ chức quản lý nhân viên của một công ty như sau:
• Thông tin về một nhân viên bao gồm lý lịch và bảng chấm công:
+ Lý lịch nhân viên :
- Mã nhân viên : chuỗi 8 ký tự
- Tên nhân viên : chuỗi 20 ký tự
- Tình trạng gia đình : 1 ký tự ( M = Married, S = Single)
- Số con: số nguyên ≤ 20
- Trình độ văn hoá: chuỗi 2 ký tự
# (C1 = cấp 1 ; C2 = cấp 2 ; C3 = cấp 3 ; ĐH = đại học; CH = cao học )
- Lương căn bản : Số ≤ 1000000
+ Chấm công nhân viên :
- Số ngày nghỉ có phép trong tháng: số ≤ 28
- Số ngày nghỉ không phép trong tháng: số ≤ 28
- Số ngày làm thêm trong tháng: số ≤ 28
- Kết quả công việc: chuỗi 2 ký tự (T = Tốt; TB = Đạt ; K = Kém)
- Lương thực lĩnh trong tháng: Số ≤ 2000000

Quy tắc tính lương :
Lương thực lĩnh = Lương căn bản + Phụ trợ trong đó nếu:
- số con > 2:                   Phụ trợ = +5%  Lương căn bản
- trình độ văn hoá = CH:        Phụ trợ = +10% Lương căn bản
- làm thêm: Phụ trội= +4% Lương căn bản/ngày


Yêu cầu : Viết chương trình quản lý nhân viên có những đặc trưng trên bằng danh sách liên kết với số lượng nhân viên không hạn chế theo những yêu cầu sau:
- Cập nhập lý lịch nhân viên, chấm công công nhân viên (thêm, xóa, tìm kiếm)
- Xem bảng lương hàng tháng
- Sắp xếp nhân viên theo thứ tự lương tăng dần với thuật toán quick sort khử đệ quy.