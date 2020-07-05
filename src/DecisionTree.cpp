/*
 * @Description: 决策树
 * @Author: szq
 * @Github: https://github.com/MrQqqq
 * @Date: 2020-06-29 01:31:54
 * @LastEditors: szq
 * @LastEditTime: 2020-06-29 02:23:09
 * @FilePath: \cpp\src\DecisionTree.cpp
 */ 

#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
class DecisionTree{
public:
    vector<vector<string>> trainData;
    vector<string> trainLabel;
    map<int,set<string>> featureValues;
    float threshold;


    void loadData(vector<vector<string>> trainData,vector<string> trainLabel){
        if(trainData.size() != trainLabel.size()){
            cerr << "input error" << endl;
            return;
        }
        this->trainData = trainData;
        this->trainLabel = trainLabel;

        //计算featureValues
        for(auto data : trainData){
            for(int i = 0;i < data.size();++i){
                featureValues[i].insert(data[i]);
            }
        }
    }

    map<string,int> labelCount(vector<int> dataset){
        map<string,int> res;
        for(int index : dataset){
            res[trainLabel[index]] += 1;
        }
        return res;
    }
    //计算信息熵
    double caculateEntropy(vector<int> dataset){
        map<string,int> label_count = labelCount(dataset);
        int len = dataset.size();
        double result = 0;
        for(auto count : label_count){
            double pi = count.second / static_cast<double>(len);
            result -= pi * log2(pi);
        }
        return result;
    }

    //或者子集
    vector<int> splitDataset(vector<int> dataset,int feature,string value){
        vector<int> res;
        for(int index : dataset){
            if(trainData[index][feature] == value){
                res.push_back(index);
            }
        }
        return res;
    }
    //计算信息增益
    double caculateGain(vector<int> dataset,int feature){
        set<string> values = featureValues[feature];
        double result = 0;
        for(string value : values){
            vector<int> subDataset = splitDataset(dataset,feature,value);
            result += subDataset.size() / static_cast<double>(dataset.size()) * caculateEntropy(subDataset);
        }
        return caculateEntropy(dataset) - result;

    }

    void createTree(vector<int> dataset,vector<int> features){
        map<string,int> label_count = labelCount(dataset);
        if(features.size() == 0){
            return 
        }
    }
    DecisionTree(vector<vector<string>> trainData,vector<string> trainLabel,int threshold){
        loadData(trainData,trainLabel);
        this->threshold = threshold;
        
    }
};