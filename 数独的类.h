//
// Created by xuyul on 25-4-20.
//

#ifndef shudu_H
#define shudu_H
#include <vector>
#include <cstddef> // 用于 size_t
#include <random>  // 用于随机数生成（生成题目时使用）

class Sudoku {
private:
    // 数独棋盘（9x9网格，0表示空白位置）
    std::vector<std::vector<int>> board;

    // 检查数字在指定位置是否合法（数独规则：行、列、3x3子网格不重复）
    // @param row    行号（0-8）
    // @param col    列号（0-8）
    // @param num    待检查的数字（1-9）
    // @return       合法返回 true，否则 false
    bool isValid(size_t row, size_t col, int num) const;

    // 递归回溯求解数独（私有实现）
    // @return       找到解返回 true，无解返回 false
    bool solve();

    // 生成一个完整的数独解（私有辅助函数）
    // @return       完整的数独解（9x9网格，无空白位置）
    std::vector<std::vector<int>> generateFullSolution() const;

    // 从完整解中随机移除数字生成题目（私有辅助函数）
    // @param fullSolution 完整的数独解
    // @param difficulty   难度（影响移除数字的数量，例如简单/中等/困难）
    // @return       生成的数独题目（包含空白位置的棋盘）
    std::vector<std::vector<int>> generatePuzzleFromSolution(
        const std::vector<std::vector<int>>& fullSolution,
        int difficulty
    ) const;

public:
    // 构造函数：初始化一个空的数独棋盘（全0）
    Sudoku();

    // 构造函数：根据初始棋盘数据初始化
    // @param initialBoard 初始棋盘数据（9x9矩阵，0表示空白）
    explicit Sudoku(const std::vector<std::vector<int>>& initialBoard);

    // 设置棋盘状态（覆盖当前棋盘）
    // @param newBoard 新的棋盘数据（9x9矩阵，0表示空白）
    void setBoard(const std::vector<std::vector<int>>& newBoard);

    // 获取当前棋盘状态（返回副本，避免外部直接修改内部数据）
    // @return  当前棋盘的副本
    std::vector<std::vector<int>> getBoard() const;

    // 打印数独棋盘到控制台（格式化显示）
    void printBoard() const;

    // 在指定位置放置数字（仅允许在空白位置放置合法数字）
    // @param row    行号（0-8）
    // @param col    列号（0-8）
    // @param num    要放置的数字（1-9，0表示清除）
    // @return       操作成功（数字合法且位置可修改）返回 true，否则 false
    bool placeNumber(size_t row, size_t col, int num);

    // 生成一个随机数独题目（带唯一解）
    // @param difficulty 难度级别（1-3，1=简单，3=困难，影响空白数量）
    // @return           生成成功返回 true，失败（如无法生成有效题目）返回 false
    bool generatePuzzle(int difficulty = 1);

    // 求解当前数独棋盘（使用回溯法）
    // @return  找到解返回 true，棋盘被修改为解；无解返回 false，棋盘状态不变
    bool solveSudoku();

    // 验证当前棋盘是否是一个有效的数独解（所有行、列、子网格合法且无空白）
    // @return  有效解返回 true，否则 false
    bool validateSolution() const;

    // 清空棋盘（所有位置设为0）
    void clearBoard();
};
#endif //数独的类_H
