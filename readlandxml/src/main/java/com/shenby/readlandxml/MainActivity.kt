package com.shenby.readlandxml

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import com.shenby.swig.LandXmlReader
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import java.io.File

class MainActivity : AppCompatActivity() {

    init {
        // 加载动态库
        System.loadLibrary("landXml")
    }


    companion object {
        const val TAG = "pugixml"
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }


        val button = findViewById<Button>(R.id.loadLandXml)
        button.setOnClickListener {
            loadLandXml(button)
        }
    }

    private fun loadLandXml(button: View) {

        lifecycleScope.launch(Dispatchers.Main) {
            button.isEnabled = false
            val landFile = checkLandFile("land", "large_xml.xml")
            val text = if (landFile != null) {
                "复制成功"
            } else {
                "复制失败"

            }
            Toast.makeText(this@MainActivity, text, Toast.LENGTH_SHORT).show()
            landFile?.let {
                readLandXmlFile(it)
            }
            button.isEnabled = true
        }


    }

    private suspend fun readLandXmlFile(file: File) = withContext(Dispatchers.Default) {
        Log.d(TAG, "readLandXmlFile: filePath: ${file.path}")
        val reader = LandXmlReader()
        reader.setLandXml(file.absolutePath)
        val success = reader.readData()
        Log.d(TAG, "readLandXmlFile: readData = $success")
        if (success) {
            val count = reader.count
            if (count > 0) {
                val faceFirst = reader.loadLandFace(0)
                val faceLast = reader.loadLandFace(count - 1)

                Log.d(TAG, "readLandXmlFile: faceFirst.x1 = ${faceFirst.x1}")
                Log.d(TAG, "readLandXmlFile: faceFirst.x2 = ${faceFirst.x2}")
                Log.d(TAG, "readLandXmlFile: faceFirst.x3 = ${faceFirst.x3}")

                Log.d(TAG, "readLandXmlFile: faceFirst = ${faceFirst.show()}")
                Log.d(TAG, "readLandXmlFile: faceLast = ${faceLast.show()}")


            }
        }


        reader.close()
    }


}