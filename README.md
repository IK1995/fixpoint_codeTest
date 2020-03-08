# fixpoint_codeTest
 
## ファイルの位置
/var/...と同じ階層にMain.cpp & makeFilename.pyを置いてください

## 実行の手順
まず、makeFilename.pyを実行
```
$python3 makeFilename.py  
```

次に、Main.cppをコンパイル  
```
$g++ --std=c++0x Main.cpp
```
出力ファイルはおそらく「a.out」のはずです  
それを実行してください
```
./a.out
```
出力ファイルがa.outでない場合は、該当の.outファイルを実行
