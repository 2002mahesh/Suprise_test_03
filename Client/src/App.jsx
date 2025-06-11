import "./style.css";
import React, { useEffect, useState } from "react";
import {
  BarChart,
  Bar,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Rectangle,
  ResponsiveContainer,
} from "recharts";

const CustomTooltip = ({ active, payload, label }) => {
  if (active && payload && payload.length) {
    const { quantity, products } = payload[0].payload;
    return (
      <div
        style={{
          background: "#fff",
          border: "1px solid #ccc",
          padding: 8,
        }}
      >
        <strong>{label}</strong>
        <div>Product: {products}</div>
        <div>Quantity: {quantity}</div>
      </div>
    );
  }
  return null;
};

export default function App() {
  const [data, setData] = useState([]);

  useEffect(() => {
    fetch("http://localhost:5000/api/data")
      .then((res) => res.json())
      .then((json) => {
        const processed = json.map((item) => ({
          ...item,
          quantity: Number(item["quantity_000_metric_tonnes_"]),
          label: `${item.month}
          (${item.products})`
        }));
        setData(processed);
      })
      .catch((err) => console.error("Error fetching data:", err));
  }, []);

  return (
    <div style={ {width: "100%",
  height: "80vh",
  maxWidth: "100vw",
  margin: "0 auto",
  padding: "20px",
  boxShadow: "0 4px 12px rgba(0, 0, 0, 0.1)",
  backgroundColor: "#fff",
  borderRadius: "12px"}}>
     <h1 style={{
  textAlign: "center",
  fontSize: "2.5rem",
  color: "#2c3e50",
  fontFamily: "'Segoe UI', Tahoma, Geneva, Verdana, sans-serif",
  marginTop: "40px",
  marginBottom: "20px",
  letterSpacing: "1px",
  textTransform: "uppercase"
}}>
  Monthly Product Quantities
</h1>
      <ResponsiveContainer width="100%" height="100%">
        <BarChart
          data={data}
          margin={{
            top:100,
            right: 30,
            left: 20,
            bottom: 0,
          }}
        >
          <CartesianGrid strokeDasharray="3 3" />
          <XAxis dataKey="label" />
          <YAxis />
          <Tooltip content={<CustomTooltip />} />
          <Bar
            dataKey="quantity"
            fill="#B3CDAD"
            activeBar={<Rectangle fill="pink" stroke="blue" />}
          />
        </BarChart>
      </ResponsiveContainer>
    </div>
  );
}
