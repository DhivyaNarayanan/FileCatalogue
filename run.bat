:run.bat

:

cls

echo  "<------------Demonstrates REQUIREMENT-3 & 8 (with /s option)---------->"

"Debug/Executive.exe" ../FileCatalogue /s *.h 


cls

echo "<------------Demonstrates REQUIREMENT-5 & 8 (with /s /d option)-------->"

"Debug/Executive.exe" ../FileCatalogue /s /d *.h *.cpp


cls

echo "<------------Demonstrates REQUIREMENT-5 & 8 (with only /d option)-------->"

"Debug/Executive.exe" ../FileCatalogue /d *.h *.cpp


cls

echo "<------------Demonstrates REQUIREMENT-6 & 8 (with /f option)-------->"

"Debug/Executive.exe" ../FileCatalogue /f"filesystem" *.h *.cpp


cls

echo "<------------Demonstrates REQUIREMENT-6 & 8 (with all options)-------->"

"Debug/Executive.exe" ../FileCatalogue /S /D /f"Demonstrates text search wrapped in two lines" *.cpp *.txt


cls

echo "<------------Demonstrates REQUIREMENT-6 & 8 (with /s /f)-------->"

"Debug/Executive.exe" ../FileCatalogue /S /f"handles tab and newline" *.txt *.h


cls

echo "<------------Demonstrates REQUIREMENT-6 (with /d /f)-------->"

"Debug/Executive.exe" ../FileCatalogue /d /f"handling of tab character" *.txt *.cpp


cls

echo "<------------Demonstrates REQUIREMENT-7 (with no options)-------->"

"Debug/Executive.exe" ../FileCatalogue *.*



echo ..............End of Demonstration.................







