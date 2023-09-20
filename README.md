# Multi-Lang-Data-Structures-Library
This is a Data Structures library with multiple programing languages
- C#
- C++
- JavaScript
- Python

This Repository is designed to help you quickly and easily select Data Structures to quickly solve problems in programming with C++, C#, JavaScript, Python languages.

This repository is also a useful document to help you study well before interviews at companies.

# Data Structure and Algorithm Lab
![image](https://github.com/nguyentungg/DataStructures/assets/16759685/19e8a63e-f0ea-4e88-92d5-e65bf4264ca0)

If you love this repository you can join with me on Data Structure and Algorithm Lab.

Together we will research and create useful things for the community.

[Discord](https://discord.gg/N8CrS3Ccsp)

# Khác biệt giữa C# và C++

- Cả C# và C++ đều có các cấu trúc dữ liệu cơ bản như mảng, danh sách liên kết, ngăn xếp, hàng đợi, cây nhị phân và bảng băm12. Tuy nhiên, cách triển khai và sử dụng chúng có thể khác nhau trong hai ngôn ngữ.

- C# là một ngôn ngữ cấp cao hơn C++, nên nó có nhiều cấu trúc dữ liệu có sẵn hơn trong thư viện chuẩn của nó1. Ví dụ, C# có các lớp như ArrayList, LinkedList, Stack, Queue, SortedList, Hashtable, Dictionary, HashSet, SortedSet và SortedDictionary trong không gian tên System.Collections3. C++ cũng có một số lớp tương tự trong thư viện chuẩn của nó, như vector, list, stack, queue, deque, map, set và unordered_map4. Tuy nhiên, C++ không có các lớp như SortedList, Hashtable hay HashSet1.

- Một điểm khác biệt quan trọng giữa các cấu trúc dữ liệu của C# và C++ là C# hỗ trợ đa hình (polymorphism) cho các kiểu dữ liệu1. Điều này có nghĩa là bạn có thể sử dụng một kiểu dữ liệu cha để tham chiếu đến một đối tượng của kiểu dữ liệu con. Ví dụ, bạn có thể sử dụng một biến kiểu IList để lưu trữ một đối tượng của kiểu ArrayList hoặc LinkedList3. Điều này cho phép bạn viết mã code linh hoạt và tái sử dụng hơn. Trong khi đó, C++ không hỗ trợ đa hình cho các kiểu dữ liệu1. Bạn phải sử dụng chính xác kiểu dữ liệu khai báo cho biến của bạn. Ví dụ, bạn không thể sử dụng một biến kiểu vector để lưu trữ một đối tượng của kiểu list4.

- Một điểm khác biệt nữa giữa các cấu trúc dữ liệu của C# và C++ là C# hỗ trợ generics (kiểu tổng quát), trong khi C++ hỗ trợ templates (mẫu)1. Generics và templates đều cho phép bạn viết mã code có thể làm việc với nhiều kiểu dữ liệu khác nhau mà không cần phải viết lại mã code cho mỗi kiểu . Tuy nhiên, generics và templates có một số khác biệt về cách triển khai và hoạt động. Một số khác biệt chính là:

    - Generics được xử lý tại runtime (thời gian chạy), trong khi templates được xử lý tại compile time (thời gian biên dịch) . Điều này có nghĩa là generics được kiểm tra lỗi và ép kiểu tại runtime, trong khi templates được kiểm tra lỗi và ép kiểu tại compile time.

    - Generics chỉ yêu cầu bạn chỉ định kiểu dữ liệu một lần khi khởi tạo một đối tượng của lớp generic. Ví dụ, bạn có thể khởi tạo một danh sách generic của kiểu int như sau: List<int> myList = new List<int>();. Sau đó, bạn có thể sử dụng myList mà không cần chỉ định kiểu dữ liệu lại. Trong khi đó, templates yêu cầu bạn chỉ định kiểu dữ liệu mỗi lần bạn sử dụng một đối tượng của lớp template. Ví dụ, bạn có thể khởi tạo một vector template của kiểu int như sau: vector<int> myVector;. Sau đó, bạn phải sử dụng myVector với kiểu dữ liệu int. Ví dụ, nếu bạn muốn thêm một phần tử vào vector, bạn phải viết: myVector.push_back<int>(10);.

    - Generics có thể bị hạn chế bởi các ràng buộc (constraints), trong khi templates không thể . Ràng buộc là các điều kiện mà kiểu dữ liệu phải thoả mãn để được sử dụng trong một lớp generic. Ví dụ, bạn có thể ràng buộc một lớp generic chỉ chấp nhận các kiểu dữ liệu có thể so sánh được bằng cách sử dụng từ khóa where. Ví dụ: class MyGenericClass<T> where T : IComparable {...}. Điều này đảm bảo rằng bạn chỉ có thể sử dụng các kiểu dữ liệu có triển khai giao diện IComparable trong lớp MyGenericClass. Trong khi đó, templates không có cơ chế ràng buộc nào, nên bạn có thể sử dụng bất kỳ kiểu dữ liệu nào trong một lớp template. Tuy nhiên, điều này có thể gây ra các lỗi biên dịch nếu kiểu dữ liệu không hỗ trợ các phép toán được sử dụng trong lớp template.