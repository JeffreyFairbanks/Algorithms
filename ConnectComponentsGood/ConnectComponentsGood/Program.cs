using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.IO;
using Newtonsoft.Json;

/// <summary>
/// This project is used as a MST, written in C#
/// Its main argument is a JSON file 
/// This code for the MST is contributed/ adapted by rathbhupendra
///        From https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
/// Done with help from Kyle Duncan  
/// </summary>

namespace ConnectComponentsGood
{
  static class Program
  {
    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    public static void Main(String[] args)
    {
      try
      {
        if (args.Length > 0)   //make sure there are the right amount of args
        {
          string filename = args[0];

          StreamReader reader = new StreamReader(filename);         //reader used to read the Json file 
          string json = reader.ReadToEnd();
          reader.Close();

          var constraints = JsonConvert.DeserializeObject<Root>(json);   //deserialize Json into the car constraints 

          var dict = new Dictionary<int, string>();   //makes a new fictionary to hold the Json file data 

          for(int i = 0; i < constraints.CountyNames.Count; i++)  //read in the counties
          {
            dict.Add(i, constraints.CountyNames[i]);
          }

          int vertices = constraints.CountyNames.Count;                     //gets the vertices and edges from the counties
          var edges = constraints.FindEdges();
          int edgeCount = edges.Count;

          Graph graph = new Graph(vertices, edgeCount, dict);  //makes a graph with the Json data that was read in previously

          for(int i = 0; i < edgeCount; i++)                        //populate the edges of the graph 
          {
            graph.edge[i].source = edges[i].Key;
            graph.edge[i].destination = edges[i].Value;
            graph.edge[i].weight = 1;
          }                                                          //building the graph


          // Function call
          graph.KruskalMST();       //calls the function that was given by: https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
                                    //now that the graph has been made, all that is needed is to work through it and output to user
        }
        else //if there is not the correct number of arguments
        {
          Console.WriteLine("There is not the correct number of arguments that were entered. \n");
          Console.WriteLine("Please use the format: {Program}.exe <adjacencyMatrix> \n");
        }

      } 
      catch  //if the try above does not work. This means there was a problem with the file. 
      {
        Console.WriteLine("The file entered could not be read. The JSON is probably not in the correct format. \n");
      }
      Console.ReadLine(); //allow the user to read the data.
    }
  }
}








