/*
I. PHÂN TÍCH SƠ BỘ GIẢI THUẬT
Bước 1: Xử lý input đầu bài
 + Xử lý trường hợp hh:60 thành (hh+1):00
 + Chuyển từ định dạng 24h sang 12h (do mặt đồng hồ chỉ có 12h nên 13h và 1h là góc như nhau)
Bước 2: Tính góc theo công thức đã được gợi ý
 + Góc của kim giờ = H x (360/12) + (M x 360)/(12 x 60)
                   = H x 30 + M x 0.5
 + Góc của kim phút = M × (360/60)
                    = M × 6
Bước 3: Tính góc
 + Lấy giá trị tuyệt đối của hiệu 2 góc
 + Nếu góc > 180 độ thì lấy 360 độ - góc


 II. MÃ GIẢ
 
*/