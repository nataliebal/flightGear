cmake_minimum_required(VERSION 3.13)
project(untitled8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled8 Expression.h BinaryExpression.h Plus.cpp Plus.h
        BinaryExpression.cpp Minus.cpp Minus.h Mult.cpp Mult.h Div.cpp Div.h
        Number.cpp Number.h ShuntingYard.cpp ShuntingYard.h Main.cpp
        DataReader.cpp DataReader.h Command.cpp Command.h CommandFactory.h PrintCommandFactory.cpp
        PrintCommandFactory.h PrintCommand.cpp PrintCommand.h VarCommand.h BindVarCommand.cpp
        BindVarCommand.h LocalVar.cpp LocalVar.h ExpressionCommand.cpp ExpressionCommand.h
        LocalVarCreator.h LocalVarCreator.cpp BindVarCreator.cpp BindVarCreator.h SleepCommandFactory.cpp
        SleepCommandFactory.h OpenDataServerCommandFactory.cpp OpenDataServerCommandFactory.h
        ConnectCommandFactory.cpp ConnectCommandFactory.h LoopCommandFactory.cpp LoopCommandFactory.h
        ConditionCommandFactory.cpp ConditionCommandFactory.h Data.cpp Data.h AssignCommandFactory.cpp
        AssignCommandFactory.h OpenDataServerCommand.cpp OpenDataServerCommand.h SleepCommand.cpp
        SleepCommand.h LoopCommand.cpp LoopCommand.h ConnectCommand.cpp ConnectCommand.h Controller.cpp
        Controller.h ConditionCommand.cpp ConditionCommand.h AssignCommand.cpp AssignCommand.h
        ConditionsCommand.h ConditionsCommand.cpp)