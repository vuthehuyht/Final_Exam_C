# Final_Exam_C
project gom 10 bai tuong ung voi 10 de
ĐỀ SỐ 1:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Khách hàng kế thừa từ lớp Người và bổ sung các thuộc tính (mã KH,
Nhóm KH) trong đó nhóm khách hàng có thể gồm: mua lẻ, mua buôn, mua qua
mạng, mã KH là một số nguyên có 5 chữ số, tự động tăng.
Khai báo lớp Mặt hàng (mã hàng, tên hàng, đơn giá), mã hàng là một số nguyên
có 5 chữ số, tự động tăng.
Khai báo lớp Hóa đơn là bạn của lớp Khách hàng và lớp Mặt hàng trong đó một
khách hàng có thể chọn mua một hoặc nhiều mặt hàng với số lượng khác nhau.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm Khách hàng vào file KH.DAT. In ra danh sách khách hàng đã có
trong file.
2. Nhập thêm Mặt hàng vào file MATHANG.DAT. In ra danh sách mặt hàng đã có
trong file.
3. Nhập danh sách mua hàng cho mỗi khách hàng đư có trong file KH.DAT. Lưu
vào file HOADON.DAT và in danh sách ra màn hình .
4. Sắp xếp danh sách mua hàng đã lưu trong HOADON.DAT
a. Theo Họ tên khách hàng
b. Theo Số lượng mặt hàng (giảm dần)
5. Lập bảng kê tổng số tiền phải trả cho mỗi khách hang
ĐỀ SỐ 2:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Lái xe kế thừa từ lớp Người và bổ sung các thuộc tính (mã LX, Trình
độ) – với quy định trình độ lái xe được chọn trong các mức từ Loại A đến Loại F,
mã LX là một số nguyên có 5 chữ số, tự động tăng.
Khai báo lớp Tuyến (mã tuyến, khoảng cách, số điểm dừng), mã tuyến là một số
nguyên có 3 chữ số, tự động tăng.
Khai báo lớp Bảng phân công là bạn của lớp Lái xe và lớp Tuyến trong đó một lái
xe trong một ngày được phân công lái xe trên một hoặc nhiều tuyến, với mỗi tuyến
cần cho biết lái xe đó sẽ lái bao nhiêu lượt. Giả sử tổng số lượt trong ngày của lái
xe không vượt quá 15.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm Lái xe vào file LX.DAT. In ra danh sách lái xe đã có trong file.
2. Nhập thêm Tuyến vào file TUYEN.DAT. In ra danh sách các tuyến đã có trong
file.
3. Nhập danh sách phân công cho mỗi lái xe đư có trong file LX.DAT; lưu vào filePHANCONG.DAT và in danh sách ra màn hình.(Chú ý: cùng một lái xe với một
tuyến không được xuất hiện quá một lần trong bảng này)
4. Sắp xếp danh sách phân công đã lưu trong PHANCONG.DAT
a. Theo Họ tên lái xe
b. Theo Số lựợng tuyến đảm nhận trong ngày (giảm dần)
5. Lập bảng kê tổng khoảng cách chạy xe trong ngày của mỗi lái xe
ĐỀ SỐ 3:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Khách hàng kế thừa từ lớp Người và bổ sung các thuộc tính (mã KH,
Loại KH) – với Loại khách hàng có thể là: cá nhân, đại diện đơn vị hành chính, đại
diện đơn vị kinh doanh, mã KH là một số nguyên có 5 chữ số, tự động tăng.
Khai báo lớp Dịch vụ (mã DV, tên DV, giá cước, đơn vị tính) mã DV là một số
nguyên có 3 chữ số, tự động tăng.
Khai báo lớp Hóa đơn là bạn của lớp Khách hàng và lớp Dịch vụ trong đó một
khách hàng có thể sử dụng một hoặc nhiều dịch vụ. Giả sử mỗi khách hàng chỉ
đựợc phép sử dụng không quá 5 loại dịch vụ khác nhau.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm khách hàng vào file KH.DAT. In ra danh sách khách hàng đã có
trong file.
2. Nhập thêm dịch vụ vào file DV.DAT. In ra danh sách dịch vụ đã có trong file.
3. Nhập hóa đơn cho mỗi khách hàng đư có trong file KH.DAT, trong đó mỗi
khách hàng ứng với một dịch vụ sử dụng sẽ có số lượng sử dụng (theo đơn vị tính);
lưu vào file HOADON.DAT và in danh sách ra màn hình. (Chú ý: cùng một khách
hàng với một loại dịch vụ thì không được xuất hiện quá một lần trong bảng này)
4. Sắp xếp danh sách hóa đơn đã lưu trong HOADON.DAT
a. Theo Họ tên khách hàng
b. Theo Số lựợng sử dụng (giảm dần)
5. Lập bảng kê số tiền phải trả cho mỗi khách hàng
ĐÊ SỐ 4:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Người mua vé kế thừa từ lớp Người bổ sung các thuộc tính (Mã
người mua, Loại người mua) – trong đó nhóm người mua có thể là: mua lẻ, mua
tập thể, mua qua mạng, mã người mua là một số nguyên có 5 chữ số, tự động tăng.Khai báo lớp Vé tàu (mã vé, loại ghế, đơn giá), mã vé là một số nguyên có 5 chữ
số, tự động tăng.
Khai báo lớp Hóa đơn là bạn của lớp Người mua vé và lớp Vé tàu, trong đó một
người mua có thể mua một hoặc nhiều vé.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm người mua vé vào file NGUOIMUA.DAT. In ra danh sách người
mua đã có trong file.
2. Nhập thêm loại vé vào file VE.DAT. In ra danh sách các loại vé đã có trong file.
3. Nhập danh sách hóa đơn mua vé cho mỗi người mua đã có trong file
NGUOIMUA.DAT; (giả sử mỗi người mua có thể mua một hoặc nhiều loại vé
nhưng không quá 4 loại, mỗi loại có một số lượng xác định nhưng không quá 20).
Lưu vào file HOADON.DAT và in danh sách ra màn hình.
4. Sắp xếp danh sách hóa đơn đã lưu trong HOADON.DAT
a. Theo Họ tên người mua
b. Theo Số lượng vé mua (giảm dần)
5. Lập bảng kê số tiền phải trả cho mỗi người mua
ĐỀ SỐ 5:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Khách hàng kế thừa từ lớp Người và bổ sung các thuộc tính (mã KH,
Loại KH) - với loại khách hàng có thể là: cá nhân, tập thể, doanh nghiệp, mã KH là
một số nguyên có 5 chữ số, tự động tăng.
Khai báo lớp Ngân hàng (mã NH, tên NH, lãi suất tiền gửi), mã NH là một số
nguyên có 3 chữ số, tự động tăng.
Khai báo lớp Số tiết kiệm là bạn của lớp Khách hàng và lớp Ngân hàng trong đó
một khách hàng có thể lập một hoặc nhiều số tiết kiệm với một hoặc nhiều ngân
hàng.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm khách hàng vào file KH.DAT. In ra danh sách khách hàng đã có
trong file.
2. Nhập thêm ngân hàng vào file NGANHANG.DAT. In ra danh sách ngân hàng
đã có trong file.
3. Nhập danh sách Sổ tiết kiệm cho mỗi khách hàng đã có trong file KH.DAT;
(mỗi khách hàng với một ngân hàng có thể có nhiều sổ khác nhau nhưng không
quá 5 sổ, mỗi sổ sẽ có số tiền gửi tương ứng), lưu danh sách vào file SOTK.DAT
và in ra màn hình.
4. Sắp xếp danh sách Sổ tiết kiệm đã lưu trong SOTK.DATa. Theo Họ tên khách hàng
b. Theo Tên Số tiền gửi
5. Lập bảng kê tổng số tiền gửi cho mỗi khách hàng
ĐỀ SỐ 6:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Sinh viên kế thừa từ lớp Người và bổ sung (mã SV, Lớp). Trong đó
mã sinh viên là một số nguyên có 5 chữ số, tự động tăng. Lớp được chọn từ danh
sách các lớp theo cách đặt tên tại Khoa Toán – Cơ – Tin học.
Khai báo lớp Môn học (mã môn, tên môn, số đvht, loại môn). Trong đó, mã môn là
một số nguyên có 3 chữ số, tự động tăng. Loại môn học có thể là Đại cương, Cơ sở
ngành, Chuyên ngành.
Khai báo lớp Bảng điểm là bạn của lớp Sinh viên và lớp Môn học trong đó một
sinh viên có một điểm cho mỗi môn học (0<=điếm<=10).
Viết chương trình trên ngôn ngữ C++ thực hiện các chức năng sau:
1. Nhập thêm sinh viên vào file SV.DAT. In ra danh sách sinh viên đã có trong
file.
2. Nhập thêm môn học vào file MONHOC.DAT. In ra danh sách môn học đã có
trong file.
3. Nhập điểm cho mỗi sinh viên đã có trong file SV.DAT; lưu vào file
BANGDIEM.DAT và in danh sách ra màn hình. (Chú ý: mỗi sinh viên với một
môn học chỉ được xuất hiện một lần trong bảng này)
4. Sắp xếp danh sách Bảng điểm đươc lưu trong BANGDIEM.DAT
a. Theo Họ tên sinh viên
b. Theo Tên Môn học
5. Tính điểm tổng kết chung cho mỗi sinh viên dựa trên điểm môn học và số đơn vị
học trình của môn học đó.
ĐỀ SỐ 7:
Khai báo lớp Người (Họ tên, Địa chỉ, SDT)
Khai báo lớp Bạn đọc kế thừa từ lớp Người và có thêm (mã thẻ đọc, loại bạn đọc),
mã bạn đọc là một số nguyên có 5 chữ số, tự động tăng. Loại bạn đọc có thể là sinh
viên, học viên cao học hoặc giáo viên.
Khai báo lớp Sách gồm các thuộc tính (mã sách, Tên sách, Tác giả, Chuyên ngành,
Năm xuất bản) – trong đó Chuyên ngành có thể là: Khoa học tự nhiên, Văn học –
Nghệ thuật, Điện tử Viễn thông, Công nghệ thông tin. Mã sách là một số nguyên
có 5 chữ số, tự động tăng.Khai báo lớp Bảng QL Mượn sách là bạn của lớp Bạn đọc và lớp Sách trong đó
một bạn đọc sẽ được phép mượn không quá 5 đầu sách khác nhau, mỗi đầu sách
không mượn quá 3 cuốn. Ghi rõ tình trạng hiện thời của sách khi cho mượn.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm đầu sách mới vào file SACH.DAT. In ra danh sách các đầu sách đư
có trong file.
2. Nhập thêm bạn đọc vào file BD.DAT. In ra danh sách bạn đọc đư có trong file.
3. Lập Bảng QL mượn sách cho từng bạn đọc bằng cách nhập các đầu sách mà bạn
đọc mượn, lưu vào file QLMS.DAT và in danh sách ra màn hình (chú ý: cùng một
loại bạn đọc với một đầu sách thì không thể xuất hiện 2 lần trong bảng này).
4. Sắp xếp danh sách Quản lý mượn sách đươc lưu trong QLMS.DAT
a. Theo tên bạn đọc
b. Theo Số lượng cuốn sách được mượn (giảm dần)
5. Tìm kiếm và hiển thị danh sách mượn sách theo tên bạn đọc
ĐỀ SỐ 8:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Sinh viên kế thừa từ lớp Người và có thêm (mã sinh viên, lớp), mã
sinh viên là một số nguyên có 5 chữ số, tự động tăng.
Khai báo lớp Môn học gồm các thuộc tính (mã môn học, Tên môn, Tổng số tiết,
Loại môn học) – trong đó Loại môn học có thể là: Đại cương, Cơ sở ngành,
Chuyên ngành bắt buộc, Chuyên ngành tự chọn. Mã môn học là một số nguyên có
3 chữ số, tự động tăng.
Khai báo lớp Bảng Đăng ký là bạn của lớp Sinh viên và lớp Môn học trong đó một
sinh viên sẽ được phép đăng ký không quá 8 môn học một học kỳ. Ghi rõ thời gian
đăng ký của sinh viên.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm môn học mới vào file MH.DAT. In ra danh sách các môn học đã có
trong file.
2. Nhập thêm sinh viên vào file SV.DAT. In ra danh sách sinh viên đã có trong
file.
3. Lập Bảng Đăng ký cho từng sinh viên bằng cách nhập các môn học cho sinh
viên đó và thời gian đăng ký (lấy từ thời gian hệ thống), lưu vào file QLDK.DAT
và in danh sách ra màn hình (chú ý: cùng một sinh viên với một môn học thì không
thể xuất hiện 2 lần trong bảng này).
4. Sắp xếp danh sách Bảng đăng ký đư lưu trong QLDK.DATa. Theo tên sinh viên
b. Theo thời gian đăng ký
5. Lập danh sách lớp học theo danh sách đăng ký. Mỗi lớp không quá 30 sinh viên
và lấy theo thứ tự thời gian đăng ký.
ĐỀ SỐ 9:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Khách hàng kế thừa từ lớp Người và có thêm (mã KH, loại KH), mã
KH là một số nguyên có 5 chữ số, tự động tăng. Loại KH có thể là: Mua lẻ hoặc
Mua buôn.
Khai báo lớp Mặt hàng gồm các thuộc tính (mã hàng, Tên hàng, Nhóm hàng, Giá
bán) – trong đó Nhóm hàng có thể là: Hàng thời trang, Hàng tiêu dùng, Hàng điện
máy, Hàng gia dụng. Mã hàng là một số nguyên có 4 chữ số, tự động tăng.
Khai báo lớp Bảng Danh sách mua hàng là bạn của lớp Khách hàng và lớp Mặt
hang trong đó với mỗi khách hàng, nhập danh sách các mặt hàng và số lượng mà
khách hang đó mua. Giả sử mỗi khách hàng không mua quá 10 loại mặt hàng một
lần.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm mặt hàng mới vào file MH.DAT. In ra danh sách các mặt hàng đã có
trong file.
2. Nhập thêm khách hàng vào file KH.DAT. In ra danh sách khách hàng đã có
trong file.
3. Lập Bảng danh sách mua hàng cho từng khách hàng, lưu vào file QLBH.DAT
và in danh sách ra màn hình (chú ý: cùng một khách hàng với một mặt hàng thì
không thể xuất hiện 2 lần trong bảng này).
4. Sắp xếp danh sách Bảng danh sách mua hàng đã lưu trong QLBH.DAT
a. Theo tên khách hàng
b. Theo tên mặt hàng
5. Lập hóa đơn cho mỗi khách hàng.
ĐỀ SỐ 10:
Khai báo lớp Người (Họ tên, Địa chỉ, Số ĐT)
Khai báo lớp Nhân viên bán hàng kế thừa từ lớp Người và có thêm (mã NV, ngày
kýhợp đồng), mã NV là một số nguyên có 4 chữ số, tự động tăng.
Khai báo lớp Mặt hàng trong kho gồm các thuộc tính (mã hàng, Tên hàng, Nhómhàng, Giá bán, Số lượng) – trong đó Nhóm hàng có thể là: Điện tử, Điện lạnh, Máy
tính, Thiết bị văn phòng. Mã hàng là một số nguyên có 4 chữ số, tự động tăng.
Khai báo lớp Bảng Danh sách bán hàng (trong một ngày) là bạn của lớp Nhân viên
và lớp Mặt hàng trong đó với mỗi nhân viên, nhập danh sách các mặt hàng mà
nhân viên đó đã bán được. Giả sử mỗi nhân viên chỉ tham gia bán tối đa 5 mặt
hàng khác nhau.
Viết chương trình trong ngôn ngữ C++ thực hiện các yêu cầu sau:
1. Nhập thêm mặt hàng mới vào file MH.DAT. In ra danh sách các mặt hàng đã có
trong file.
2. Nhập thêm nhân viên vào file NV.DAT. In ra danh sách nhân viên đã có trong
file.
3. Lập Bảng danh sách bán hàng cho từng nhân viên, lưu vào file QLBH.DAT và
in danh sách ra màn hình (chú ý: cùng một nhân viên với một mặt hàng thì không
thể xuất hiện 2 lần trong bảng này).
4. Sắp xếp danh sách Bảng danh sách bán hàng đãợc lưu trong QLBH.DAT
a. Theo tên nhân viên
b. Theo nhóm mặt hàng
5. Lập bảng kê doanh thu cho mỗi nhân viên.
