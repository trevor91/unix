������ ���� ������ �ݿ��ϵ��� small-shell�� update�Ͻÿ�.

 

1. cd command�� �����ϵ��� �����Ͻÿ�.

2. ���� 3���� signal, SIGTSTP; SIGQUIT; SIGINT�� catch�Ͽ� �� ������ �͹̳ο� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.(��, �̶� smallsh�� ������� �ʵ��� �ۼ�)

3. pipeline ����� �����ϵ��� �����Ͻÿ�.

3.1 ���� ex) ls -al | grep unix

3.2 ��ø ex) prog1 | prog2 | prog3

4. redirection ����� �����ϵ��� �����Ͻÿ�.

ex) ls ?al > tmp.txt

ex) sort < ./tmp.txt (���� ��, tmp.log < dmesg)

5. exit�� �Է��� ��� �����Ͻÿ�.