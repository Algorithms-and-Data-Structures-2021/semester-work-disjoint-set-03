# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.
add_executable(demo_benchmark demo_benchmark.cpp)
add_executable(find_benchmark find_multiple_benchmark.cpp)
add_executable(join_benchmark join_multiple_benchmark.cpp)
add_executable(make_set_benchmark make_set_multiple_benchmark.cpp)
add_executable(find_multiple_benchmark find_multiple_benchmark.cpp)
add_executable(join_multiple_benchmark join_multiple_benchmark.cpp)
add_executable(make_set_multiple_benchmark make_set_multiple_benchmark.cpp)

# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(demo_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(find_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(join_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(make_set_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(find_multiple_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(join_multiple_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(make_set_multiple_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
