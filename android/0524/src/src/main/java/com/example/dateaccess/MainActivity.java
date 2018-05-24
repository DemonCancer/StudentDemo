package com.example.dateaccess;

import android.content.ContentValues;
import android.database.Cursor;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Button btnquery,btninsert;
    TextView tv1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnquery=findViewById(R.id.btnquery);
        btninsert=findViewById(R.id.btninsert);
        tv1=findViewById(R.id.tv1);
        btnquery.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String  queryResult="";
                Uri uri=Uri.parse("content://com.example.test0524.provider/Book");
                Cursor cursor=getContentResolver().query(uri,null,null,null,null);
                while (cursor.moveToNext()){
                    String name=cursor.getString(cursor.getColumnIndex("name"));
                    String author=cursor.getString(cursor.getColumnIndex("author"));
                    int pages=cursor.getInt(cursor.getColumnIndex("pages"));
                    double price=cursor.getDouble(cursor.getColumnIndex("price"));

                    queryResult=queryResult+name+"\t"+author+"\t"+pages+"\t"+price+"\n";
                }
                cursor.close();
                tv1.setText(queryResult);
            }
        });
        ///
        btninsert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ContentValues values=new ContentValues();
                values.put("name","第二行Android代码");
                values.put("author","郭霖二");
                values.put("pages",501);
                values.put("price",88.2);
                /*db.insert("Book",null,values);
                values.clear();*/
                Uri uri=Uri.parse("content://com.example.test0524.provider/Book");
                Uri newUri=getContentResolver().insert(uri,values);

                Toast.makeText(MainActivity.this, "插入完成", Toast.LENGTH_SHORT).show();

            }
        });
        ///
    }











}
