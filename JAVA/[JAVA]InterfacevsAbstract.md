## Interface vs Abstract

### 추상 메서드(Abstract Method)

- abstract 키워드와 함께 원형만 선언되고, 코드는 작성되지 않은 메서드

```java
public abstract double getArea(); // 추상 메서드
public abstract int getScore(){return 100;} // 추상 메서드 아님. 컴파일 에러 발생
```

### 추상 클래스(Abstract Class)

- 개념: Abstract 키워드로 선언된 클래스.
  - 추상 메서드를 최소 한 개 이상 가지고 abstract로 선언된 클래스
    - 최소 한 개 이상의 추상 메서드를 포함하는 경우, __반드시__ 추상 클래스로 선언되어야 한다.
  - 추상 메서드가 없어도 abstract로 선언한 클래스
    - 추상 메서드가 하나도 없는 경우에도, 추상 클래스로 선언할 수 있다.
- 구현
  - Sub class에서 Super class의 모든 추상 메서드를 Overriding하여 실행 가능한 코드로 구현.
- 목적
  - 객체(Instance)를 생성하기 위함이 아니며, 상속을 위한 __부모 클래스로 활용__하기 위한 것.
  - 추상 클래스의 추상 메서드를 자식 클래스가 구체화하여 그 기능을 확장하는 데에 목적을 둠.



```java
abstract class Figure{
  Figure(){...}
 	abstract public double getArea();
}
class Circle extends Figure{
  public double getArea(){return 1.23456;}//추상 메서드 오버라이딩
}
```



### 인터페이스(Interface)

- 개념: 추상 메서드와 상수__만__ 포함하며, interface 키워드를 사용하여 선언.

- 구현:

  - interface를 상속받고, 추상 메서드를 __모두__ 구현한 클래스를 작성.
  - __implements__ 키워드를 사용하여 구현

- 목적: 

  - 구현 객체의 같은 동작을 보장하기 위해
  - 서로 관련이 없는 클래스에서 공통적으로 사용하는 방식이 필요하지만, 기능을 각각 구현할 필요가 있는 경우에 사용.

- 특징

  - 상수 필드와 추상 메서드만으로 구성
  - 모든 메서드는 추상 메서드로, abstract public 속성이며 생략 가능하다.
  - 모든 상수는 public static final 속성이며, 생략하여 선언할 수 있음.
  - 인터페이스를 상속받아 새로운 인터페이스를 만들 수 있음.
    - `interface Circle extends Figure{...}`

  ```java
  interface Figure{
    double RADIUS = 3;//public static final int RADIUS=3;과 동일
    double getArea();//abstract public double getArea()와 동일
  }
  
  class Circle implements Figure{
    //Figure의 모든 추상 메서드를 구현
    public double getArea(){return 1.2345;}
    //추가적으로 다른 메서드를 작성할 수 있음.
    public double getRadius(){return 3;}
  }
  ```



### 추상 클래스(Abstract Class)와 인터페이스(Interface)의 공통점

- 인스턴스(객체)는 생성할 수 없다.
- 선언만 있고 구현 내용이 없다.
- 자식 클래스가 메서드의 구체적인 동작을 구현하도록 책임을 위임한다.



### 추상 클래스(Abstract Class)와 인터페이스(Interface)의 차이점

- 서로 다른 목적을 가지고 있다.
  - 추상클래스: 추상 메서드를 자식 클래스가 구체화하여, 그 기능을 확장하는 데에 목적.(상속을 위한 부모클래스)
  - 인터페이스: 서로 관련이 없는 클래스에서 공통적으로 사용하는 방식이 필요하지만 __각각 구현할 필요__가 있는 경우에 사용.
- 추상 클래스는 클래스이지만, 인터페이스는 클래스가 아니다.
- 추상 클래스는 단일 상속이지만, 인터페이스는 다중 상속이 가능하다.

