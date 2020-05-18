## 오버로딩과 오버라이딩

### 오버로딩(Overloading)

- 두 메서드가 같은 이름을 가지고 있으나, 인자의 수나 자료형이 다른 경우
- Ex)
  - `public double calculateArea(Circle c){...}`
  - `public double calculateArea(Circle c1, Circle c2){...}`
  - `public double calculateArea(Square c) {...}`



### 오버라이딩(Overriding)

- 상위 클래스의 메서드 이름과 용례(signature)가 같은 함수를 하위 클래스에 재정의하는 것.

- 상속 관계에 있는 클래스 간에 같은 이름의 메서드를 정의

- Ex)

  ```java
  public abstract class Figure{
    public void print(){System.out.println("Shape");}
    public abstract double calculateArea();
  }
  public class Circle extends Figure{
    private double radius = 3;
    @Override
    public void print(){System.out.println("Circle");}
    public double calculateArea(){return radius * radius * 3.14;}
  }
  ```

  

