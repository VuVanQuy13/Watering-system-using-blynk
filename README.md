1.	Mô phỏng mạch trên phần mềm altium
![image](https://github.com/user-attachments/assets/a5bc8870-3927-426a-b88c-370210113897)

2.	Mô phỏng mạch in
![image](https://github.com/user-attachments/assets/e444bc82-d831-449d-a204-c768e1e1475b)

3.	Nguyên lý hoạt động

•	Cảm biến đo độ ẩm đất đưa ra tín hiệu điện áp tương ứng với độ ẩm. Điện áp này được đưa vào một trong các đầu vào của IC LM358.

•	LM358 so sánh điện áp từ cảm biến với một điện áp chuẩn được thiết lập bởi chiết áp đơn 10k. Khi điện áp từ cảm biến vượt qua ngưỡng này (đất đủ khô), đầu ra của 
LM358 sẽ thay đổi trạng thái.

•	 Nếu đầu ra của LM358 cho thấy đất khô (ngõ ra logic cao), tín hiệu này sẽ kích hoạt opto 817, kích hoạt relay.

•	Khi relay được kích hoạt, tiếp điểm sẽ đóng lại, bật thiết bị bơm nước. Diode 1N4007 bảo vệ relay khỏi dòng điện ngược khi tắt mạch.

•	Đọc tín hiệu từ cảm biến để hiển thị giá trị độ ẩm lên màn hình LCD và kiểm tra trạng thái relay để hiển thị trạng thái hệ thống.

•	Màn hình LCD sẽ hiển thị trạng thái độ ẩm đất đo được và trạng thái bơm (bật/tắt).

•	Xem giá trị độ ẩm và bật/tắt relay qua app blynk.
