1. Kế thừa: Một đối tượng lớp con sẽ có đầy đủ các thuộc tính và phương thức của lớp cha.
2. Đóng gói: Một đối tượng chỉ giao tiếp với thế giới bên ngoài thông qua các method cần thiết, không cần cho thế giới biết các thông tin nội tại.
3. Trừu tượng: Các method của một đối tượng thì thế giới bên ngoài chỉ cần sử dụng, không cần biết method đó được code như thế nào, chỉ cần biết nó nhận vào cái gì, trả về cái gì là được.
4. Đa hình: cùng một method đó, các class con của cùng một class cha có thể code khác nhau.

1. Kế thừa là lớp con sẽ có hết những thuộc tính và phương thức của lớp cha thông qua từ khóa extend
2. Đóng gói là cách mình che đậy một số thông tin thông qua các access modifier như public, protected, defautl, private
3. Đa hình là có 2 khái niệm là overriding và overloading. Overriding là mình sẽ thay đổi lại hành vi xử lý của 1 method. Còn overloading là có nhiều method cùng tên nhưng khác số lượng, thứ tự các parameter.
4. Còn trừu tượng hóa là có 2 thứ là abstract class và interface.