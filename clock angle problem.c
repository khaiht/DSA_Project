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
 calculateClockAngle(hour, minute):
    // Xử lý input
    if minute == 60:
        minute = 0
        hour = hour + 1
    
    // Chuyển sang định dạng 12h
    if hour > 12:
        hour = hour - 12
    if hour == 0:
        hour = 12
    
    // Tính góc của kim giờ và phút
    hour_angle = hour * 30 + minute * 0.5
    minute_angle = minute * 6
    
    // Tính góc giữa giờ và phút
    angle = abs(hour_angle - minute_angle)
    if angle > 180:
        angle = angle - 180
    
    return angle
*/


/*
III. CÀI ĐẶT CHƯƠNG TRÌNH
*/
#include <stdio.h>
#include <math.h>

double calculateClockAngle(int hour, int minute){
    // Xử lý phút = 60
    if(minute == 60){
        minute = 0;
        hour = hour + 1;
    }
    
    // Chuyển sang định dạng 12h
    if(hour > 12)
        hour = hour - 12;
    if(hour == 0)
        hour = 12;
    
    // Tính góc của kim giờ
    double hour_angle = hour * 30 + minute * 0.5;

    // Tính góc của kim phút
    double minute_angle = minute * 6;

    // Tính góc giữa kim giờ và kim phút
    double angle = fabs(hour_angle - minute_angle);

    // Nếu góc lớn hơn 180 độ
    if(angle > 180)
        angle = angle - 180;

    return angle;
}

void Tests(){
    printf("Test case:\n");
    
    // Trường hợp cơ bản
    printf("11:50 -> %.1f°\n", calculateClockAngle(11, 50));

    // Trường hợp lớn hơn 12h
    printf("12:45 -> %.1f°\n", calculateClockAngle(12, 45));

    // Trường hợp 12:00
    printf("12:00 -> %.1f°\n", calculateClockAngle(12, 0));

    // Trường hợp 0h
    printf("0:15 -> %.1f°\n", calculateClockAngle(0, 15));

    // Trường hợp 60 phút
    printf("9:60 -> %.1f°\n", calculateClockAngle(9, 60));
}

int main(){
    // Chạy test
    Tests();

    // Demo nhap tu ban phim
    int hour, minute;
    printf("\nNhập giờ và phút (định dạng hh:mm): ");
    scanf("%d %d", &hour, &minute);
    
    double angle = calculateClockAngle(hour, minute);
    printf("Góc giữa kim giờ và kim phút: %.1f°\n", angle);
    
    return 0;
}