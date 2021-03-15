# EXAM RANK 02

## 시험 시작하기
* 티켓 만들기
~~~
kinit (인트라 id)
~~~
* examshell 접속하기
~~~
examshell
~~~

## vim 설정하기
* 경로 위치 
~~~
~/.myvimrc
~~~
* 옵션 추가
~~~
set nu    // 라인 번호 
syntax on // 글자 색상
~~~

## 🚨 inter 주의사항 및 예외 처리 🚨

        #include <unistd.h> - write()

        main 명령행 인자 argc(ARGument Count), argv(ARGument Vector) 사용

        agrc : 명령행 인자의 개수
        argv : 명령행 인자 데이터 또는 값

        기본적으로 argv의 첫번째 인덱스 데이터(argv[0])에는 프로그램의 실행경로가 고정적으로 저장되어져있다.
        따라서 argc도 기본 값은 1이다.

        inter : 첫번째 인자 문자열의 각 문자들 중
        두번째 인자 문자열에도 속해있는 문자 출력
        단, 이미 출력된 문자를 중복 출력할 수 없다.

        만약 인자가 2개가 아닐 경우 '\n'를 출력하고 프로그램을 종료한다.

        dupl_check 함수 구현 - 어떠한 문자열에서 출력하려는 문자의 중복 체크

<hr>

## 🚨 union 주의사항 및 예외 처리 🚨

        #include <unistd.h> - write()

        main 명령행 인자 argc(ARGument Count), argv(ARGument Vector) 사용

        agrc : 명령행 인자의 개수
        argv : 명령행 인자 데이터 또는 값

        기본적으로 argv의 첫번째 인덱스 데이터(argv[0])에는 프로그램의 실행경로가 고정적으로 저장되어져있다.
        따라서 argc도 기본 값은 1이다.

        union : 첫번째 인자 문자열부터 두번째 인자 문자열까지 
        구성된 문자들을 순서대로 출력.
        단, 이미 출력된 문자를 중복 출력할 수 없다.

        만약 인자가 2개가 아닐 경우 '\n'를 출력하고 프로그램을 종료한다.

        dupl_check 함수 구현 - 어떠한 문자열에서 출력하려는 문자의 중복 체크

<hr>

## 🚨 get_next_line 주의사항 및 예외 처리 🚨

        get_next_line 함수는 main 문안의 루프안에서 실행되어진다.

        파일 디스크립터 0 : stdin 에서 라인을 읽어와 line 변수에 저장해야한다.

        라인의 기준은 파일의 내용에서 '\n' 또는 EOF 으로 끝나는 문자열을 기준으로 한다.

        line에 '\n'는 저장하지 않는다.

        파일의 마지막 라인을 읽으면 return : 0
        파일의 마지막 라인이 아닌 라인을 읽으면 return : 1
        파일 읽기의 에러가 발생했다면 return : -1

        파일의 EOF에 도달했을 때 현재 버퍼에 있는 값들을 line에 저장하고 만약 버퍼가 비어 있다면 빈 문자열을 line에 저장해야 한다.

        파일의 EOF에 도달했을 때 마지막 버퍼를 제외하고는 모든 메모리는 해제되어야 한다.

        line도 해제 가능한 변수여야 한다.
        
        우리가 만든 함수는 표준 출력, 파일에서도 잘 읽어와야 한다.

header file

        조건부 컴파일 사용 - #ifndef & # define & #endif

        필요한 헤더파일 포함    - <unistd.h> : read()
                                - <stdlib.h> : malloc(), free()

        (선택) BUFFER_SIZE, OPEN_MAX 매크로 상수 정의

        get_next_line 함수 선언

malloc

        malloc 오류 처리 구현

        malloc 할당 시 '\0' 포함하여 크기 설정

        메모리 해제 검토 

<hr>

## 🚨 ft_printf 주의사항 및 예외 처리 🚨

        '%s', '%d', '%x' 서식 지정자에 대해서만 구현

        너비 플래그와 정밀도 플래그에 대해서만 구현

        최종 출력된 문장의 길이를 리턴
        
header

        <unistd.h> : write()
        <stdlib.h> : malloc(), free()
        <stdarg.h> : va_list, va_start(), 
malloc

        malloc 오류 처리 구현

        malloc 할당 시 '\0' 포함하여 크기 설정

        메모리 해제 검토 
flag

        너비, 정밀도 플래그 이외에 플래그 문자가 존재할 경우 
        무시되어져야 한다. ('-' 정렬 플래그)

        너비 플래그는 가변 인자 값의 길이보다 클 때만 적용된다.

        정밀도 플래그 너비가 0이거나 지정되어있지 않을 경우
        가변 인자 값을 출력하지 않는다.

function

        고정 인자 문자열 서식에서 데이터 타입을 만나지 못했을 경우 
        고정 인자 문자열 인덱스를 증가시키면 안된다.


        ft_itoa 함수에서 매개변수로 변환할 수를 받을 때 long long 타입으로 받아야한다.
        (오버/언더플로우 예외처리)
        
        ft_itoa 함수에서 받아온 숫자가 음수일 경우에 대한 처리도 수행해야한다.

        '%s'의 가변인자가 NULL일 경우 "(null)" 문자열을 출력하도록 설계해야한다.

        '%s' 서식 지정자에서 정밀도 플래그는 가변 인자 문자열의 길이보다 작을 때에만 적용된다.

        '%d' 서식 지정자에서 정밀도 플래그가 적용되었을 경우 부호는 적용되어진 가변 인자 값 전방에 위치해야한다.

# Practice 

## **1 Try**

        inter : 00:12:14

        union : 00:12:14

        get_next_line : 00:31:30

        ft_print : 02:18:38

## **2 Try**

        inter : 00:18:01

        union : 00:14:54

        get_next_line : 00:35:13

        ft_print : 01:46:24

## **3 Try**

        inter : 00:11:46

        union : 00:07:42

        get_next_line : 00:23:17

        ft_print : 00:51:43

# Last Practice 

## **inter & get_next_line**

        00:54:10

## **inter & ft_printf**


## **union & get_next_line**


## **union & ft_printf**

        00:58:00

<hr>

# 지금까지 실수한/헷갈렸던 부분

**inter**

        dupl_check 매개변수 구성

        1. (중복체크 대상 문자열, 찾을 문자, 찾을 문자의 인덱스)

        2. (중복체크 대상 문자열, 찾을 문자, 검색 범위의 마지막 인덱스) - 추천

        ==============================================================

        1.      - 추천
        while 첫번째 명령 인자 탐색
                if 출력할 문자 중복 검사
                        while 두번째 명령 인자 탐색
                                if 출력할 문자 두번째 명령 인자 조건 검사
                                        write 출력
        
        2.
        while 첫번째 명령 인자 탐색
                while 두번째 명령 인자 탐색
                        if 출력할 문자 중복 검사
                                if 출력할 문자 두번째 명령 인자 조건 검사
                                        write 출력
        
        3.
        while 첫번째 명령 인자 탐색
                while 두번째 명령 인자 탐색
                        if 출력할 문자 두번째 명령 인자 조건 검사
                                if 출력할 문자 중복 검사
                                        write 출력

**union**

        첫번째 명령 인자를 출력하려는 경우 if문 1개

        두번째 명령 인자를 출력하려는 경우 if문 2개 (중첩 or AND 연산)

        즉, 두번째 명령 인자의 각 문자들을 첫번째 명령 인자와의 중복체크를 해야하고,

        두번째 명령 인자에서 이전 인덱스의 문자들과도 중복 체크를 해야한다.

**get_next_line**

        char    *buff

        buff 변수 메모리 해제 주의 !

        ft_strjoin을 통해 buff 변수가 메모리 해제되어버리면

        다음 처리 과정을 올바르게 진행할 수 없음 주의!!!

        웬만하면 buff 변수 선언 시 크기까지 같이 설정해주는 것이 더 나을 수도 있다.

        ex) char    buff[2];

        ==============================================================

        ft_substr 함수 매개변수 구성

        1. (자를 대상 문자열, 자를 문자열의 시작 인덱스, 자를 문자열의 길이) - 추천

        2. (자를 대상 문자열, 자를 문자열의 시작 인덱스, 자를 문자열의 마지막 인덱스)

        2번의 경우 메모리 할당 크기 설정 관련해서 헷갈릴 수 있음

        개행 문자의 위치 인덱스를 3번째 매개변수로 넘겨줄 때도 헷갈릴 수 있음

**ft_print**

        코드 빠뜨리지 않기 !!! => 급하게 코딩하지말라 !!!

        ==============================================================

        ft_itoa 함수의 if 문 구성

        ( num / n진수 > 0 ) 조건은 n진법으로 표현할 수 없다는 것을 의미한다.

                =>      n진법으로 표현하기 위해 자릿수를 늘려야한다는 것을 의미.

        그렇기 때문에 재귀함수를 통해 더 작게 나눈다.

        위 조건에 부합하지 않을 경우
        
        ( num % n진수 ) 값을 저장한다.

        이때부터 재귀 함수를 호출했던 곳으로 돌아가 

        값을 조합한다.

        다음 코드가 가장 이상적이고 깔끔한 코드라고 생각한다.

```c++
static	char	*ft_itoa(long long num, char *base)
{
	char	*result;
	int	base_len;

	if (num < 0)
		num *= -1;
	base_len = ft_strlen(base);
	if (num / base_len > 0)
	{
		result = ft_strjoin(ft_itoa(num / base_len, base), ft_substr(ft_strdup(base), num % base_len, 1));
	}
	else
		result = ft_substr(ft_strdup(base), num % base_len, 1); 
	return (result);
}
```

<hr>
